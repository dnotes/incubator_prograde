<?php
// $Id$

/**
 * @file
 *
 */

function incubator_events_incubator_settings_menu() {
  return array('description' => 'Settings for events and calendars.');
}

function incubator_events_incubator_settings() {
  $form['incubator_events_views_choice'] = array(
    '#type' => 'select',
    '#title' => t('Primary view of events'),
    '#options' => array('calendar' => t('Calendar'), 'list' => t('Event List'), 'both' => t('Both')),
    '#default_value' => variable_get('incubator_events_views_choice', 'calendar'),
    '#description' => t('Whichever view is chosen as primary will appear in the main menu.'),
  );
  $form['incubator_events_views_disable_secondary'] = array(
    '#type' => 'checkbox',
    '#title' => t('Completely disable the non-primary view'),
    '#default_value' => variable_get('incubator_events_views_disable_secondary', FALSE),
    '#description' => t('If this option is checked, whichever view is not enabled above will be completely unreachable as a page.'),
  );
  $form['incubator_events_add_groups_submenu'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add event listing pages for activity groups'),
    '#default_value' => variable_get('incubator_events_add_groups_submenu', TRUE),
    '#description' => t('Activity group listings present upcoming events in a
 search-friendly way; however, for sites with few events for children and youth,
 to avoid constantly blank lists it might be desirable not to show these links.'),
  );
  $form['incubator_events_views_upcoming_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for upcoming events link'),
    '#default_value' => ($title = db_query('SELECT link_title FROM menu_links WHERE router_path = ?', array('events/upcoming'))->fetchField()) ? $title : variable_get('incubator_events_views_upcoming_title', 'Upcoming Events'),
  );
  $form['incubator_events_views_calendar_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for calendar link'),
    '#default_value' => ($title = db_query('SELECT link_title FROM menu_links WHERE router_path = ?', array('events/calendar'))->fetchField()) ? $title : variable_get('incubator_events_views_calendar_title', 'Calendar'),
  );

  $form['calendar'] = array(
    '#type' => 'fieldset',
    '#title' => t('Calendar display options')
  );
  $form['calendar']['incubator_events_views_calendar_firstday'] = array(
    '#type' => 'select',
    '#title' => t('First day of week'),
    '#options' => array(
      '0' => t('Sunday'),
      '1' => t('Monday'),
      '2' => t('Tuesday'),
      '3' => t('Wednesday'),
      '4' => t('Thursday'),
      '5' => t('Friday'),
      '6' => t('Saturday'),
    ),
    '#default_value' => variable_get('incubator_events_views_calendar_firstday', '0'),
  );
  $form['calendar']['incubator_events_views_calendar_weekmode'] = array(
    '#type' => 'select',
    '#title' => t('Display of weeks on month view'),
    '#options' => array(
      'fixed' => t('Always show 6 weeks'),
      'liquid' => t('Show 4, 5, or 6 weeks with constant calendar height'),
      'variable' => t('Show 4, 5, or 6 weeks with constant row height'),
    ),
    '#default_value' => variable_get('incubator_events_views_calendar_weekmode', 'variable'),
  );
  $form['calendar']['incubator_events_views_calendar_editable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow drag / drop editing of events on calendar'),
    '#default_value' => variable_get('incubator_events_views_calendar_editable', TRUE),
    '#description' => t('Note that drag / drop editing does NOT work on repeating events.')
  );
  $form['calendar']['incubator_events_show_bahai_calendar'] = array(
    '#type' => 'checkbox',
    '#title' => t("Show the Bahá'í calendar holy days"),
    '#default_value' => variable_get('incubator_events_show_bahai_calendar', module_exists('incubator_core_activities')),
  );
  
  $form['activities_page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Activities page'),
    '#description' => t('The activities page presents a view of upcoming events
 organized by the day of the week.  It may be useful for communities that have
 many regularly-occurring activities.')
  );
  $form['activities_page']['incubator_events_views_enable_activities_page'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable activities pages'),
    '#default_value' => variable_get('incubator_events_views_enable_activities_page', FALSE),
  );

  $form = system_settings_form($form);
  $form['#submit'][] = 'incubator_events_admin_form_submit';                    // this must be after the system form submit function

  return $form;
}

function incubator_events_admin_form_submit(&$form, &$form_state) {
  foreach (array('events/calendar', 'events/upcoming') as $path) {
    if ($link = db_query('SELECT * FROM {menu_links} WHERE link_path = :path', array(':path' => $path))->fetchAssoc()) {
      $var_name = ($path == 'events/calendar') ? 'list' : 'calendar';
      $title = ($path == 'events/calendar') ?
        variable_get('incubator_events_views_calendar_title', 'Calendar') :
        variable_get('incubator_events_views_upcoming_title', 'Upcoming Events');
      $link['hidden'] = (variable_get('incubator_events_views_choice', 'calendar') == $var_name) ? 1 : 0;
      $link['link_title'] = $title;
      $link['customized'] = 1;
      $link['options'] = unserialize($link['options']);
      menu_link_save($link);
    }
  }

  cache_clear_all('ctools_export:views_view:upcoming_events', 'cache_views');
  cache_clear_all('ctools_export:views_view:activities_upcoming_events', 'cache_views');
  menu_rebuild();
  if (module_exists('redirect') && !variable_get('incubator_events_views_disable_secondary', FALSE)) {
    redirect_delete_by_path('events/calendar');
    redirect_delete_by_path('events/upcoming');
  }
}
