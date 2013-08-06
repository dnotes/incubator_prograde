<?php
// $Id$

/**
 * @file
 *
 */

function incubator_events_views_data_alter(&$data) {
  if (module_exists('views_date_format_sql')) {
    $data['field_data_field_event_date']['field_event_date_value']['field'] = array(
      'table' => 'field_data_field_event_date',
      'handler' => 'views_date_format_sql_handler_field_date',
      'click sortable' => 1,
      'additional fields' => array(),
      'entity_tables' => array(
        'node' => 'node',
        'node_revision' => 'node',
      ),
      'element_type' => 'div',
      'is revision' => 0,
    );
  }
}

function incubator_events_views_query_alter(&$view, &$query) {

  // The activities view organizes and groups upcoming events by day, and to do
  // this it uses the date_format_sql module as well as some tricks and hacks.
  //
  // There are two fields retrieved for the date, both based on the column
  // field_data_field_event_date_field_event_date_value:
  //
  // field_data_field_event_date_field_event_date_value, or "Day"
  // is the named day of the week, e.g. Sunday.  It is the date that is displayed.
  //
  // field_data_field_event_date_field_event_date_value_1 or "Day of week"
  // is the numerical day of the week, and is used for sorting the events, since
  // if the name were used, they would not sort according to the order of the days
  // in the week.
  if ($view->name == 'activities_upcoming_events' && in_array($view->current_display, array('default', 'page'))) {
    // Since date fields retrieve separate values for each occurrence of repeating events,
    // we must remove the date_delta fields from the query in order for the grouping to work.
    unset($query->fields['field_data_field_event_date_delta']);
    unset($query->fields['date_delta_date_filter']);
    // Also, for pgsql support, we must change the formatting string for the numerical day of week field.
    $replacement = db_driver() == 'pgsql' ? 'D' : '%w';
    $query->fields['field_data_field_event_date_field_event_date_value_1']['field'] =
      str_replace("'w'", "'$replacement'", $query->fields['field_data_field_event_date_field_event_date_value_1']['field']);
    // Finally, we must add the sort to the query, and it doesn't work to add it
    // in the views interface.
    array_unshift($query->orderby, array(
      'field' => 'field_data_field_event_date_field_event_date_value_1',
      'direction' => 'ASC'
    ));
  }
  elseif($view->name == 'upcoming_events' && in_array($view->current_display, array('page', 'page_1')) && !variable_get('incubator_events_views_disable_secondary', FALSE)) {
    
    // On taxonomy term pages, we remove the link to the alternate view.
    if (!empty($view->args[0]) && is_numeric($tid = $view->args[0])) {
      $view->display_handler->handlers['header']['area']->options['content'] = '';
    }
    // For the base upcoming events and calendar views without arguments,
    // we add a link to the alternate view in code so that it can be translated.
    // We also change the empty text to remove any term reference.
    else {
      $path = ($view->current_display == 'page') ? 'events/calendar' : 'events/upcoming';
      $text = ($view->current_display == 'page') ? t('View full calendar') : t('View upcoming events list');
      $view->display_handler->handlers['header']['area']->options['content'] = l($text, $path);
      $view->display_handler->handlers['empty']['area']->options['content'] = t('There are no upcoming events.');
    }
    // On the calendar we trigger logic for showing Baha'i Holy Days.
    if ($view->current_display == 'page_1') {
      incubator_events_show_bahai_calendar();
    }
  }
  elseif($view->name == 'localities' && $view->current_display == 'block_1' && arg(1) == 'calendar') {
    // If the current view is the calendar, we want the localities links to point
    // to the calendar for each community instead of the list of upcoming events.
    $view->display_handler->handlers['field']['name']->options['alter']['path'] = 'events/calendar/[tid]';
  }
  elseif($view->name == 'map_events') {
    $query->add_where_expression(0, "(SELECT MIN(ned.field_event_date_value) FROM {field_data_field_event_date} ned WHERE ned.revision_id = node.vid AND ned.field_event_date_value > :time AND ned.field_event_date_value < :time2) IS NOT NULL", array(':time' => strtotime('-2 hours'), ':time2' => strtotime('+3 months')));
  }
}

function incubator_events_show_bahai_calendar() {
  if (variable_get('incubator_events_show_bahai_calendar', module_exists('incubator_core_activities'))) {
    global $language;
    if (!$cache = cache_get("incubatorbahaicalendar:$language->language")) {
      $years = array(
        date('Y') - 1,
        date('Y'),
        date('Y') + 1,
      );
      $holyday = array(
        '03-21' => t("Naw-Rúz (New Year)"), // non-breaking space in New Year
        '04-21' => t("First Day of Riḍván"),
        '04-29' => t("Ninth Day of Riḍván"),
        '05-02' => t("Twelfth Day of Riḍván"),
        '05-23' => t("Declaration of The Báb"),
        '05-29' => t("Ascension of Bahá'u'lláh"),
        '07-09' => t("Martyrdom of The Báb"),
        '10-20' => t("Birth of The Báb"),
        '11-12' => t("Birth of Bahá'u'lláh"),
      );
      $workingholyday = array(
        '04-22' => t('Riḍván Festival'),
        '04-23' => t('Riḍván Festival'),
        '04-24' => t('Riḍván Festival'),
        '04-25' => t('Riḍván Festival'),
        '04-26' => t('Riḍván Festival'),
        '04-27' => t('Riḍván Festival'),
        '04-28' => t('Riḍván Festival'),
        '04-30' => t('Riḍván Festival'),
        '05-01' => t('Riḍván Festival'),
        '11-26' => t("Day of the Covenant"),
        '11-28' => t("Ascension of 'Abdu'l‑Bahá"), // non-breaking hyphen
      );
      $feast = array(
        '03-21' => t("Bahá (Splendor)"),
        '04-09' => t("Jalál (Glory)"),
        '04-28' => t("Jamál (Beauty)"),
        '05-17' => t("‘Aẓamat (Grandeur)"),
        '06-05' => t("Núr (Light)"),
        '06-24' => t("Raḥmat (Mercy)"),
        '07-13' => t("Kalimát (Words)"),
        '08-01' => t("Kamál (Perfection)"),
        '08-20' => t("Asmá’ (Names)"),
        '09-08' => t("‘Izzát (Might)"),
        '09-27' => t("Mashíyyat (Will)"),
        '10-16' => t("‘Ilm (Knowledge)"),
        '11-04' => t("Qudrat (Power)"),
        '11-23' => t("Qawl (Speech)"),
        '12-12' => t("Masá'il (Questions)"),
        '12-31' => t("Sharaf (Honor)"),
        '01-19' => t("Sulṭán (Sovereignty)"),
        '02-07' => t("Mulk (Dominion)"),
        '03-02' => t("‘Alá’ (Loftiness)"),
      );
      $ayyamiha = array(
        '02-26' => t('Ayyám-i-Há'),
        '02-27' => t('Ayyám-i-Há'),
        '02-28' => t('Ayyám-i-Há'),
        '03-01' => t('Ayyám-i-Há'),
      );
      foreach (array('holyday', 'workingholyday', 'feast', 'ayyamiha') as $var) {
        foreach ($$var as $day => $name) {
          foreach ($years as $year) {
            $events[] = array(
              'title' => $name,
              'start' => "$year-$day",
              'className' => "bahaical $var",
            );
          }
        }
      }
      foreach ($years as $year) {
        if (date('L', mktime(0, 0, 0, 1, 1, $year))) {
          $events[] = array(
            'title' => t('Ayyám-i-Há'),
            'start' => "$year-02-29",
            'className' => 'bahaical ayyamiha',
          );
        }
      }
      cache_set("incubatorbahaicalendar:$language->language", $events, 'cache', strtotime('+1 week'));
    }
    else {
      $events = $cache->data;
    }
    drupal_add_css(drupal_get_path('module', 'incubator_events') . '/css/bahaicalendar.css');
    drupal_add_js(array('incubatorBahaiCalendar' => array(
      'events' => $events,
      'editable' => FALSE,
      'allDayDefault' => TRUE,
      'ignoreTimezone' => TRUE,
    )), 'setting');
  }
}
