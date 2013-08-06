<?php
// $Id$

/**
 * @file
 *
 */

function incubator_report($tables = FALSE, $anon = FALSE) {

  $nodetypes = _incubator_nodetype_reports();                                   // get data for content type reports
  if (!$nodetypes) {                                                            // exit if there is NO content...
    return t('No content has been published.');
  }
  if (!$tables) {                                                               // don't add js if the user wants to see tables
    drupal_add_js('https://www.google.com/jsapi', 'external');
    drupal_add_js(drupal_get_path('module', 'incubator') . '/files/incubator_reports.js');
  }

  foreach (array_keys(_incubator_reports_datearray()) as $value) {              // create the $header array for history graphs
    $header[] = date('M', strtotime($value));
  }
  array_unshift($header, ' ');


// CONTENT TYPE DISTRIBUTION REPORTS
  $ret = '<h2>' . t('Types of content created') . '</h2><p>' .
  t('These reports tell you in general what kinds of content your site contains,
    as well as trends in what kinds of content are being created.') .
  '</p><div class="incubator-reports-row">';
  foreach ($nodetypes as $record) {
    $rows[] = array(                                                            // create data table for overview
      t($record->name),
      ($tables ? $record->count : (int) $record->count)
    );
    $row = array(t($record->name));                                             // create data table for history
    foreach ($record->history as $month => $count) {                            //
      $row[] = ($tables ? $count : (int) $count);                               //
    }                                                                           //
    $history_rows[] = $row;                                                     //
  }
  //=========================

  $table = array(                                                               // CONTENT TYPE DISTRIBUTION OVERVIEW
    'header' => array(t('Type'), t('Count')),
    'rows' => $rows,
    'caption' => t('Content type distribution'),
  );
  $ret .= '<div id="nodetypes-total" class="incubator-report left">' . theme('table', $table) . '</div>';

  $js_settings['incubator_reports']['nodetypes-total'] = array_merge($table,    // setup data for google charts
    array('type' => 'PieChart', 'data' => $table['rows']));                     // and add the header
  array_unshift($js_settings['incubator_reports']['nodetypes-total']['data'], $table['header']);
  $rows = array();
  //=========================
  
  $table = array(                                                               // CONTENT TYPE DISTRIBUTION HISTORY
    'header' => $header,
    'rows' => $history_rows,
    'caption' => t('Amount of content of each type created over 12 months')
  );
  $ret .= '<div id="nodetypes-history" class="incubator-report wide">' . theme('table', $table) . '</div></div>';

  $data = $table['rows'];                                                       // setup data for google charts
  array_unshift($data, $table['header']);                                       // add the header
  $data = _incubator_reports_transpose($data);                                  // array must be transposed for line charts
  $js_settings['incubator_reports']['nodetypes-history'] = array_merge($table,  //
    array('type' => 'LineChart', 'data' => $data));                             //
  $history_rows = array();                                                      //
  //=========================


// COLLABORATION REPORTS
  $authors = _incubator_authorship_reports($anon);                              // get data for authorship reports, respecting $anon

  if (!$authors) {                                                              // exit if there is no content in the past year
    drupal_add_js($js_settings, 'setting');                                     // ... but first, add the existing js
    return $ret . t('No content has been created in the past year.');
  }

  $ret .= '<h2>' . t('Levels of collaboration') . '</h2><p>' .
  t('These charts attempt to measure levels of collaboration on your site.  All
    content created by the top contributor over the past year is considered
    "Individual" effort, content created by the top 5 contributors is "Team",
    by the top 50 contributors is "Community", and beyond that is "World".') .
  '</p><div class="incubator-reports-row">';

  foreach (array('Individual', 'Team', 'Community', 'World') as $group) {
    if (!empty($authors[$group])) {
      $rows[] = array(                                                          // setup data for overview
        $group,
        ($tables ? $authors[$group]['count'] : (int) $authors[$group]['count']),// add numbers for google charts only
        $authors[$group]['names']
      );
      $row = array($group);                                                     // setup data for history
      foreach ($authors[$group]['history'] as $month => $count) {               //
        $row[] = $tables ? $count : (int) $count;                               // add numbers for google charts only
      }                                                                         //
      $historical_rows[] = $row;                                                //
    }
  }
  //=========================

  $table= array(                                                                // COLLABORATION OVERVIEW
    'header' => array('', t('Count'), t('People')),
    'rows' => $rows,
    'caption' => t('Collaboration level for the past year'),
  );
  $ret .= '<div id="collaboration-total" class="incubator-report left">' . theme('table', $table) . '</div>';
  $js_settings['incubator_reports']['collaboration-total'] = array_merge($table, // add js for google charts
    array('type' => 'PieChart', 'data' => $table['rows']));                     // ... including the header
  array_unshift($js_settings['incubator_reports']['collaboration-total']['data'], $table['header']);
  $rows = array();
  //=========================

  $table = array(                                                               // COLLABORATION HISTORY
    'header' => $header,
    'rows' => $historical_rows,
    'caption' => t('Amount of content created over 12 months, separated by author group'),
  );
  $ret .= '<div id="collaboration-history" class="incubator-report wide">' . theme('table', $table) . '</div></div>';

  $data = $table['rows'];                                                       // prepare data for google charts
  array_unshift($data, $table['header']);                                       // and add the header
  $data = _incubator_reports_transpose($data);                                  // data must be transposed for area charts
  $js_settings['incubator_reports']['collaboration-history'] = array_merge($table,  //
    array('type' => 'AreaChart', 'data' => $data));                             //
  $rows = array();
  //=========================


// TOP CONTRIBUTORS REPORTS
  $ret .= '<h2>' . t('Top contributors') . '</h2><p>' .
  t('These reports measure the amount of content created by the top contributors
    over the past year.  The historical view may be helpful to better understand
    trends in the collaboration reports above.') .
  '</p><div class="incubator-reports-row">';
  foreach ($authors['users'] as $i => $account) {
    if ($i == 10) { continue; }
    $rows[] = array(                                                            // setup data for overview
      $account->str,                                                            //
      ($tables ? $account->count : (int) $account->count)                       // add numbers for google charts only
    );
    if (is_array($account->history)) {                                          // setup data for history
      $row = array($account->str);                                              // account->str is the title
      foreach ($account->history as $month => $count) {                         //
        $row[] = $tables ? $count : (int) $count;                               // add numbers for google charts only
      }                                                                         //
      $history_rows[] = $row;                                                   //
    }
  }

  $table = array(                                                               // CONTRIBUTORS OVERVIEW
    'header' => array('', t('Count')),
    'rows' => $rows,
    'caption' => t('Top contributors for the past year'),
  );
  $ret .= '<div id="contributors-total" class="incubator-report left">' . theme('table', $table) . '</div>';

  $data = $table['rows'];                                                       // setup overview data for google charts
  array_unshift($data, $table['header']);                                       // add the header
  $data = _incubator_reports_transpose($data);                                  // bar chart data must be transposed
  $js_settings['incubator_reports']['contributors-total'] = array_merge($table, // compose js settings
    array('type' => 'BarChart', 'data' => $data));
  $rows = array();
  //=========================

  $table = array(                                                               // CONTRIBUTORS HISTORY
    'header' => $header,
    'rows' => $history_rows,
    'caption' => t('Amount of content created over 12 months')
  );
  $ret .= '<div id="contributors-history" class="incubator-report wide">' . theme('table', $table) . '</div></div>';

  $data = $table['rows'];                                                       // setup history data for google charts
  array_unshift($data, $table['header']);                                       // add the header
  $data = _incubator_reports_transpose($data);                                  // line chart data must be transposed
  $js_settings['incubator_reports']['contributors-history'] = array_merge($table,  //
    array('type' => 'LineChart', 'data' => $data));                             // compose js
  $history_rows = array();

  if (!$tables) {                                                                // add js only if the user is not viewing tables
    foreach ($js_settings['incubator_reports'] as $key => $array) {             // add sizes for elements
      $js_settings['incubator_reports'][$key]['height'] = 260;
      $js_settings['incubator_reports'][$key]['width'] = stripos($key, 'history') ? 700 : 340;
    }
    drupal_add_js($js_settings, 'setting');
  }

  return $ret;
}

function _incubator_nodetype_reports() {
  $query = db_query('SELECT COUNT(n.nid) count, n.type, t.name FROM {node} n
    LEFT JOIN {node_type} t ON t.type = n.type
    WHERE n.status = 1 GROUP BY type ORDER BY count DESC');
  foreach ($query as $record) {
    $record->history = _incubator_nodetype_history($record->type);
    $nodetypes[] = $record;
  }
  return $nodetypes;
}

function _incubator_nodetype_history($type) {
  $startdate = _incubator_reports_startdate();
  $return = _incubator_reports_datearray();
  $query = db_query('SELECT FROM_UNIXTIME(n.created, \'%Y-%m\') month, COUNT(n.nid) count
    FROM {node} n WHERE n.status = 1 AND n.created >= :startdate AND n.type = :type
    GROUP BY month ORDER BY count DESC', array(':startdate' => $startdate, ':type' => $type));
  foreach ($query as $result) {
    $return[$result->month] = $result->count;
  }
  return $return;
}

/**
 *
 * @return array
 * 'startdate': unixtime for the first day of the current month, previous year
 * 'Individual': uid, count, names, history for the top 1 contributor
 * 'Team': uids, count, names, history for the next 4 contributors
 * 'Community': uids, count, names, history for the next 45 contributors
 * 'World': count, names, history for all other contributors
 * 'users': uid, name, count, history for the top 9 contributors
 *
 * each 'uids' item is an array of uids.
 *
 * each 'names' item is a string of usernames, or if the query is anonymous,
 * a count of contributors in that category.
 *
 * each 'history' item is an array of counts for each of the last 12 months,
 * keyed by month in the format Y-m.  The current month is also included, though
 * naturally the counts are incomplete.
 *
 */
function _incubator_authorship_reports($anon = FALSE) {

  $startdate = _incubator_reports_startdate();

  // Authorship reports : multiple reports based on content authorship
  $query = db_query('SELECT COUNT(n.nid) count, n.uid, u.name FROM {node} n
    LEFT JOIN {users} u ON u.uid = n.uid
    WHERE n.status = 1 AND n.created >= :start AND n.nid > 1 AND n.uid > 0
    GROUP BY n.uid ORDER BY count DESC LIMIT 0,50', array(':start' => $startdate));
  $i = 1; $type = t('Individual');
  foreach ($query as $record) {
    $record->str = $anon ? "#$i ($type)" : "#$i $record->name";
    $record->history = _incubator_authorship_history($startdate, $record->uid);
    $users[] = $record;
    $i++;
    $type = ($i < 6) ? t('Team') : t('Community');
  }
  if (empty($users)) { return FALSE; }
  if ($users) {
    $ret['Individual'] = array('uids' => array($users[0]->uid), 'count' => $users[0]->count);
    $ret['Individual']['names'] = $anon ? t('top contributor') : $users[0]->name;
    $ret['Individual']['history'] = _incubator_authorship_history($startdate, $users[0]->uid);
  }
  if (count($users) > 1) {
    for ($i = 1; $i <= 4; $i++) {
      if (!$users[$i]) { continue; }
      $ret['Team']['uids'][] = $users[$i]->uid;
      $ret['Team']['names'] = $anon ? format_plural($i, '1 other contributor', 'next @count contributors') : $ret['Team']['names'] . "{$users[$i]->name} ";
      $ret['Team']['count'] += $users[$i]->count;
    }
    $ret['Team']['history'] = _incubator_authorship_history($startdate, $ret['Team']['uids']);
  }
  if (count($users) > 5) {
    for ($i = 5; $i <= 49; $i++) {
      if (!$users[$i]) { continue; }
      $ret['Community']['uids'][] = $users[$i]->uid;
      $ret['Community']['count'] += $users[$i]->count;
    }
    $ret['Community']['names'] = format_plural($i - 4, '1 other contributor', 'next @count contributors');
    $ret['Community']['history'] = _incubator_authorship_history($startdate, $ret['Community']['uids']);
  }
  if (count($users) == 50) {
    $uids = array_merge($usertop['uids'], $userteam['uids'], $usercomm['uids']);
    $worldcounts = db_query('SELECT COUNT(nid) nids, COUNT(uid) uids FROM {node}
      WHERE uid NOT IN (:uids)', array(':uids' => $uids))->fetchObject();
    $ret['World']['count'] = $worldcounts->nids;
    $ret['World']['names'] = format_plural($worldcounts->uids, '1 other contributor', '@count other contributors');
    $ret['World']['history'] = _incubator_authorship_history($startdate, $uids, TRUE);
  }
  $ret['users'] = $users;
  $ret['startdate'] = $startdate;
  if ($anon) {
    foreach (array('Individual', 'Team', 'Community', 'World') as $group) {
      if (!empty($ret[$group])) {
        unset($ret[$group]['uids']);
      }
    }
    foreach ($users as $id => $user) {
      unset ($users[$id]->uid);
      unset ($users[$id]->name);
    }
  }
  return $ret;
}

function _incubator_authorship_history($startdate, $uids, $exclude = FALSE) {
  if (!is_array($uids)) {
    $uids = array($uids);
  }
  $return = _incubator_reports_datearray();
  $query = db_query('SELECT FROM_UNIXTIME(n.created, \'%Y-%m\') month, COUNT(n.nid) count
    FROM {node} n WHERE status = 1 AND n.created >= :start AND uid IN (:uids) AND nid > 1
    GROUP BY month ORDER BY month ASC', array(':start' => $startdate, ':uids' => $uids));
  foreach ($query as $result) {
    $return[$result->month] = $result->count;
  }
  return $return;
}

function _incubator_reports_startdate() {
  static $startdate;
  if (!$startdate) {
    $curmonth = date('n');
    $lastyear = date('Y', strtotime('-1 year'));
    $startdate = mktime(0,0,0,$curmonth,1,$lastyear);
  }
  return $startdate;
}

function _incubator_reports_datearray() {
  static $datearray;
  if (!is_array($datearray)) {
    $m = date('n', _incubator_reports_startdate());
    $y = date('Y', _incubator_reports_startdate());
    for ($i = 1; $i < 14; $i++) {
      $datearray[$y . '-' . str_pad($m, 2, 0, STR_PAD_LEFT)] = '';
      if ($m == 12) {
        $m = 1; $y++;
      }
      else {
        $m++;
      }
    }
  }
  return $datearray;
}

function _incubator_reports_transpose($array) {
  foreach ($array as $key => $sub) {
    foreach ($sub as $k => $v) {
      $ret[$k][$key] = $v;
    }
  }
  return $ret;
}
