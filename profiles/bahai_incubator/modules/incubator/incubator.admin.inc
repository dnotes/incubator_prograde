<?php
// $Id$

/**
 * @file
 *
 */

function incubator_image_settings() {
  $form['incubator_images'] = array(
    '#title' => t('Main image float direction'),
    '#description' => t('Direction that all "main image" contents will float.'),
    '#type' => 'select',
    '#options' => array('left' => t('Left', array(), array('#context' => 'Direction')), 'right' => t('Right', array(), array('#context' => 'Direction'))),
    '#default_value' => variable_get('incubator_images', 'right'),
  );
  $form['incubator_images_small_size'] = array(
    '#title' => t('Small image size (in pixels)'),
    '#description' => t('Images in lists of content will have this length as their largest dimension.  Preview videos will appear this size.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('incubator_images_thumbnail_size', INCUBATOR_IMAGES_THUMBNAIL_SIZE),
  );
  $form['incubator_images_medium_size'] = array(
    '#title' => t('Medium image size (in pixels)'),
    '#description' => t('Main images on page views will have this length as their largest dimension.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('incubator_images_medium_size', INCUBATOR_IMAGES_MEDIUM_SIZE),
  );
  $form['incubator_images_large_size'] = array(
    '#title' => t('Large image size (in pixels)'),
    '#description' => t('Zoomed images in colorboxes will have this length as their largest dimension.  Full videos will appear in this size.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('incubator_images_large_size', INCUBATOR_IMAGES_LARGE_SIZE),
  );
  $form['warning'] = array(
    '#markup' => t('Submitting this form will flush all caches on your site.  This may impact performance for a short time.  ')
  );

  $form = system_settings_form($form);
  $form['#submit'][] = 'incubator_admin_settings_submit';
  return $form;
}

function incubator_image_settings_submit(&$form, &$form_state) {
  // flush ALL CACHES.
  drupal_flush_all_caches();

  // flush image styles for thumbnail, medium, large
  image_style_flush(image_style_load('thumbnail'));
  image_style_flush(image_style_load('medium'));
  image_style_flush(image_style_load('large'));
  image_style_flush(image_style_load('slideshow'));

  // set video small display size
  // set video large display size
  foreach (array('small', 'large') as $display_name) {
    $view_mode = "media_$display_name";
    $displays = file_displays_load('video', $view_mode, TRUE);
    foreach (array('vimeo', 'youtube') as $provider) {
      $formatter_name = "media_{$provider}_video";
      if (!empty($displays[$formatter_name])) {
        $default_display = _incubator_file_display_video_default($provider, $display_name);
        $sizes = array_intersect_key($default_display, array('height' => 1, 'width' => 1));
        $display = isset($displays[$formatter_name]) ? (array) $displays[$formatter_name] : (array) file_display_new($file_type, $view_mode, $formatter_name);
        $display['settings'] = array_merge($default_display, $display['settings'], $sizes);
        file_display_save((object) $display);
      }
    }
  }

}

/** 
 * Helper function for setting video sizes to match image sizes.
 * 
 * All videos and images are sized at a 4:3 ratio.  
 * 
 * There are three image sizes: thumbnail, medium, and large.  They are defined
 * by their default widths: thumbnail = 212px, medium = 360px, large = 600px.
 * 
 * There are three video displays used: small, large, and 'link'.  Small and 
 * link both display an image of the video ONLY, in thumbnail and large sizes
 * respectively.  Large displays the actual video in full size.  This should
 * change in the future for the sake of clarity.
 * 
 */
function _incubator_file_display_video_default($provider, $display_name = 'small') {
  if (!module_load_include('inc', "media_$provider", "includes/media_$provider.variables") &&
      !module_load_include('inc', "media_$provider", "media_$provider.variables")) {
    return FALSE;
  }
  if (function_exists($function = "media_{$provider}_variable_default")) {
    $settings = $function();
    unset($settings['preview_uri']);
    $image_size = ($display_name == 'small' ? 'thumbnail' : 'large');
    $width = variable_get("incubator_images_{$image_size}_size", constant('INCUBATOR_IMAGES_' . strtoupper($image_size) . '_SIZE'));
    $settings['width'] = $width;
    $settings['height'] = (string) round($width * .75, 0);
    if ($provider == 'youtube') {
      $settings = array_merge($settings, array('related' => FALSE, 'showsearch' => FALSE, 'modestbranding' => TRUE));
      if ($display_name == 'large') {
        $settings['hd'] = TRUE;
      }
    }
    return $settings;
  }
  return FALSE;
}

function incubator_feature_settings() {
  $form = array();
  $modules = array(
    'incubator_announcements',
    'incubator_core_activities',
    'incubator_blog',
    'incubator_events',
    'incubator_facilities',
    'incubator_gallery',
    'incubator_localities',
    'incubator_mapping',
    'incubator_news',
    'incubator_video',
    'incubator_content_review',
    'incubator_private',
    'incubator_social',
  );
  drupal_alter('incubator_module_list', $modules);
  $form['modules_enabled'] = array('#tree' => TRUE);
  $form['modules_disabled'] = array('#tree' => TRUE);
  foreach ($modules as $module) {
    $info = drupal_parse_info_file(drupal_get_path('module', $module) . "/$module.info");
    $enabled = module_exists($module);
    $formlevel = $enabled ? 'modules_enabled' : 'modules_disabled';
    $form[$formlevel]["$module"] = array(
      '#type' => 'fieldset',
      '#title' => t($info['name']),
      '#description' => t($info['description']),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
      '#attributes' => array(
        'class' => array(($enabled ? 'enabled' : 'not-enabled'))
      ),
      'enabled' => array(
        '#type' => 'checkbox',
        '#title' => $module,
        '#default_value' => $enabled,
      ),
      'mask' => array(
        '#markup' => '<div class="incubator-feature-mask"></div>'
      ),
      'changed' => array(
        '#markup' => '<div class="changes-not-saved">' . t('save changes below') . '</div>',
      ),
    );
    
    // Include weight
    if (!empty($info['incubator_weight'])) {
      if ($info['incubator_weight'] < 0) {
        $form[$formlevel]["$module"]['#attributes']['class'][] = 'incubator-main';
      }
      $form[$formlevel]["$module"]['#weight'] = $info['incubator_weight'];
    }
    
    // Include information about current content
    if (!empty($info['incubator_nodetype'])) {
      if ($count = db_query("SELECT COUNT(nid) FROM {node} n WHERE n.type = :type AND n.status", array(':type' => $info['incubator_nodetype']))->fetchfield()) {
        $content_info = '<p class="content-info">' . format_plural($count, '1 published node', '@count published nodes', array('@count' => $count)) . '</p>';
      }
    }
    elseif (!empty($info['incubator_taxonomy'])) {
      if ($v = taxonomy_vocabulary_machine_name_load($info['incubator_taxonomy'])) {
        if ($count = db_query("SELECT COUNT (DISTINCT(nid)) FROM {taxonomy_index} ti 
                INNER JOIN {taxonomy_term_data} td ON (td.tid = ti.tid)
                WHERE td.vid = :vocid", array(':vocid' => $v->vid))->fetchfield()) {
          $content_info = '<p class="content-info">' . format_plural($count, '1 tagged node', '@count tagged nodes', array('@count' => $count)) . '</p>';
        }
      }
    }
    elseif ($module == 'incubator_private' && module_exists('incubator_private')) {
      if ($count = db_query('SELECT COUNT(nid) FROM {private} WHERE private > ?', array(0))->fetchField()) {
        $content_info = '<p class="content-info">' . format_plural($count, '1 private node', '@count private nodes', array('@count' => $count)) .
          ' <span class="warning">' . t('(if this module is disabled, all content will be public)') . '</span></p>';
      }
    }
    
    // Include icon
    if (!empty($info['incubator_icon'])) {
      $form[$formlevel]["$module"]['#attributes']['style'][] = 'background-image:url(/' . drupal_get_path('module', $module) . "/{$info['incubator_icon']});";
    }
    if (!empty($content_info)) {
      $form[$formlevel]["$module"]['#description'] = $content_info . $form[$formlevel]["$module"]['#description'];
      unset($content_info);
    }
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  drupal_add_css(drupal_get_path('module', 'incubator') . '/files/incubator-admin.css');
  drupal_add_js(drupal_get_path('module', 'incubator') . '/files/incubator-admin.js');
  return $form;
}

function incubator_feature_settings_submit(&$form, &$form_state) {
  if (!empty($form_state['values']['modules_enabled'])) {
    foreach($form_state['values']['modules_enabled'] as $module => $value) {
      if (!$value['enabled']) {
        $disable_modules[] = $module;
      }
    }
  }
  if (!empty($form_state['values']['modules_disabled'])) {
    foreach($form_state['values']['modules_disabled'] as $module => $value) {
      if ($value['enabled']) {
        $enable_modules[] = $module;
      }
    }
  }
  if (!empty($enable_modules)) {
    module_enable($enable_modules);
  }
  if (!empty($disable_modules)) {
    module_disable($disable_modules);
  }
}

function _incubator_frontpage_get_blocks() {
  $views = _incubator_frontpage_get_views();
  unset($views[0]);
  return db_select('block')
    ->fields('block')
    ->condition('module', 'views')
    ->condition('delta', array_keys($views), 'IN')
    ->condition('theme', variable_get('theme_default', 'incubator_standard_theme'))
    ->condition('status', 0, '>')
    ->condition(db_or()
      ->condition(db_and()->condition('visibility', 1)->condition('pages', '%<front>%', 'LIKE'))
      ->condition(db_and()->condition('visibility', 0)->condition('pages', '%<front>%', 'NOT LIKE'))
    )
    ->execute()->fetchAllAssoc('delta');
}

function _incubator_frontpage_get_views() {
  if ($incubator_frontpage_views = &drupal_static(__FUNCTION__)) {
    return $incubator_frontpage_views;
  }
  // Set the view of recent content to be used on the frontpage
  $view = views_get_view('recent_stories');
  $incubator_frontpage_views = array(0 => t('- None -'));
  foreach ($view->display as $display) {
    if ($display->id != 'default') {
      $incubator_frontpage_views["recent_stories-{$display->id}"] = t($display->display_title); // This should be secure enough; users with "administer views" are inherently insecure anyhow.
    }
  }
  drupal_alter('incubator_frontpage_views', $incubator_frontpage_views);
  return $incubator_frontpage_views;
}

function incubator_frontpage_settings() {
  $form = array();
  
  $incubator_frontpage_views = _incubator_frontpage_get_views();
  $blocks = _incubator_frontpage_get_blocks();
  if (empty($blocks)) {
    $default = 0;
  }
  elseif (count($blocks) > 1) {
    $default = NULL;
  }
  else {
    $block = array_shift($blocks);
    $default = $block->delta;
  }
  
  $form['frontpage_view'] = array(
    '#type' => 'select',
    '#title' => t('Recent content view'),
    '#options' => $incubator_frontpage_views,
    '#default_value' => !empty($default) ? $default : 0,
  );
  if (is_null($default)) {
    $form['frontpage_view'] += array(
      '#disabled' => TRUE,
      '#description' => t('Since you have more than one view displayed on the front page, you cannot use this setting.'),
    );
  }

    if (!module_exists('views_slideshow_cycle')) {
    $form['enable_slideshows'] = array(
      '#type' => 'submit',
      '#value' => t('Enable slideshows'),
    );
  }

  // Conditional displays for other elements
  foreach ($incubator_frontpage_views as $id => $title) {
    if (stripos($id, 'recent_stories') === FALSE) {
      $recent_stories_visible[':input[name="frontpage_view"], .kungfu' . $id] = array('!value' => $id);
    }
    if (stripos($id, 'slides') === FALSE) {
      $slideshows_visible[':input[name="frontpage_view"], .kungfu' . $id] = array('!value' => $id);
    }
  }
  
  $form['vars'] = array('#tree' => TRUE);
  
  // Settings for the recent stories view
  $form['vars']['recent_stories'] = array(
    '#type' => 'fieldset',
    '#title' => 'Recent stories view',
    '#states' => array('visible' => $recent_stories_visible),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    'incubator_recent_stories_title' => array(
      '#title' => t('Title'),
      '#type' => 'textfield',
      '#default_value' => variable_get('incubator_recent_stories_title', 'Recent Stories'),
    ),
    'incubator_recent_stories_count' => array(
      '#title' => t('Number of recent stories to display'),
      '#type' => 'textfield',
      '#size' => 5,
      '#description' => t('to display all items, set this value to 0'),
      '#default_value' => variable_get('incubator_recent_stories_count', 5),
      '#element_validate' => array('element_validate_number'),
    ),
  );
  
  // Settings for slideshows
  $effects = array(
    'none' => 'none',
    'blindX' => 'blindX',
    'blindY' => 'blindY',
    'blindZ' => 'blindZ',
    'cover' => 'cover',
    'curtainX' => 'curtainX',
    'curtainY' => 'curtainY',
    'fade' => 'fade',
    'fadeZoom' => 'fadeZoom',
    'growX' => 'growX',
    'growY' => 'growY',
    'scrollUp' => 'scrollUp',
    'scrollDown' => 'scrollDown',
    'scrollLeft' => 'scrollLeft',
    'scrollRight' => 'scrollRight',
    'scrollHorz' => 'scrollHorz',
    'scrollVert' => 'scrollVert',
    'shuffle' => 'shuffle',
    'slideX' => 'slideX',
    'slideY' => 'slideY',
    'toss' => 'toss',
    'turnUp' => 'turnUp',
    'turnDown' => 'turnDown',
    'turnLeft' => 'turnLeft',
    'turnRight' => 'turnRight',
    'uncover' => 'uncover',
    'wipe' => 'wipe',
    'zoom' => 'zoom'
  );  
  $form['vars']['slideshows'] = array(
    '#type' => 'fieldset',
    '#title' => t('Slideshows'),
    '#states' => array('visible' => $slideshows_visible),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    'incubator_slideshows_effect' => array(
      '#type' => 'select',
      '#options' => $effects,
      '#title' => t('Slide transition effect'),
      '#default_value' => variable_get('incubator_slideshows_effect', 'scrollHorz'),
    ),
    'incubator_slideshows_timeout' => array(
      '#type' => 'textfield',
      '#title' => t('Time between slide transitions'),
      '#default_value' => variable_get('incubator_slideshows_timeout', '5000'),
      '#element_validate' => array('element_validate_number'),
      '#description' => t('ms', array(), array('context' => 'Time length : milliseconds')),
      '#size' => 5,
    ),
    'incubator_slideshows_speed' => array(
      '#type' => 'textfield',
      '#title' => t('Speed of slide transitions'),
      '#default_value' => variable_get('incubator_slideshows_speed', '700'),
      '#element_validate' => array('element_validate_number'),
      '#description' => t('ms', array(), array('context' => 'Time length : milliseconds')),
      '#size' => 5,
    ),
    'incubator_slideshows_delay' => array(
      '#type' => 'textfield',
      '#title' => t('Extra delay on first slide'),
      '#default_value' => variable_get('incubator_slideshows_delay', '0'),
      '#element_validate' => array('element_validate_number'),
      '#description' => t('ms', array(), array('context' => 'Time length : milliseconds')),
      '#size' => 5,
    ),
  );
  
  // Set which content types are promoted by default
  $form['promoted_content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Promoted content'),
    '#description' => t('Content that is "promoted" will appear in the front page recent content view.
      <strong>New content</strong> of the types checked below will be promoted to the front page by default.
      Existing content will not be affected by changes to this form.'),
    '#tree' => TRUE,
  );
  foreach (node_type_get_names() as $type => $name) {
    $options = variable_get("node_options_$type", array());
    $form['promoted_content'][$type] = array(
      '#type' => 'checkbox',
      '#title' => check_plain($name),
      '#default_value' => in_array('promote', $options)
    );
  }
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  
  drupal_add_css(drupal_get_path('module', 'incubator') . '/files/incubator-admin-frontpage.css');
  return $form;
}

function incubator_frontpage_settings_validate(&$form, &$form_state) {
  if (!empty($form_state['values']['frontpage_view'])) {
    $blocks = _incubator_frontpage_get_blocks();
    if (is_array($blocks) && count($blocks) > 1) {
      form_set_error('frontpage_view', t('Since you have more than one view displayed on the front page, you cannot use this setting.'));
    }
  }
}

function incubator_frontpage_settings_submit(&$form, &$form_state) {
  if ($form_state['clicked_button']['#value'] == t('Enable slideshows')) {
    module_enable(array('views_slideshow_cycle'));
  }
  $blocks = _incubator_frontpage_get_blocks();
  // If there is a block enabled already
  if (!empty($blocks)) {
    $block = array_shift($blocks);
    // Change an already enabled block if a value was given
    if (!empty($form_state['values']['frontpage_view'])) {
      // Only if it's not the same value as already enabled
      if ($form_state['values']['frontpage_view'] != $block->delta) {
        $new_block = (array) $block;
        unset($new_block['bid']);
        $new_block['delta'] = $form_state['values']['frontpage_view'];
        // If the new block already exists, update it and set the old to disabled
        if ($bid = db_query('SELECT bid FROM {block} WHERE module = ? AND delta = ? AND theme = ?',
          array('views', $form_state['values']['frontpage_view'], variable_get('theme_default', 'incubator_standard_theme')))->fetchField()) {
          db_update('block')->fields($new_block)->condition('bid', $bid)->execute();
          db_update('block')->fields(array('status' => 0))->condition('bid', $block->bid)->execute();
        }
        // If the new block does not exist, create it and set the old to disabled
        else {
          db_insert('block')->fields($new_block)->execute();
          db_update('block')->fields(array('status' => 0))->condition('bid', $block->bid)->execute();
        }
      }
    }
    // Delete the existing block if no value was given
    else {
      db_update('block')->fields(array('status' => 0))->condition('bid', $block->bid)->execute();
    }
  }
  // If no block is currently enabled but a value was given, enable a block
  elseif (!empty($form_state['values']['frontpage_view'])) {
    // If the requested block already exists, update it
    if ($bid = db_query('SELECT bid FROM {block} WHERE module = ? AND delta = ? AND theme = ?',
      array('views', $form_state['values']['frontpage_view'], variable_get('theme_default', 'incubator_standard_theme')))->fetchField()) {
      db_update('block')->fields(array('status' => 1))->condition('bid', $bid)->execute();
    }
    // If the requested block does not exist, create it
    else {
      module_load_install('incubator');
      module_load_install('bahai_incubator');
      $blocks = bahai_incubator_incubator_default_blocks(array('views:recent_stories'));
      $blocks['views:recent_stories']['delta'] = $form_state['values']['frontpage_view'];
      _incubator_enable_blocks($blocks);
    }
  }
  
  foreach ($form_state['values']['promoted_content'] as $type => $promote) {
    $options = variable_get("node_options_$type", array());
    if ($promote) {
      $options = array_merge($options, array('promote'));
    }
    else {
      $options = array_diff($options, array('promote'));
    }
    variable_set("node_options_$type", $options);
    
  }
  foreach ($form_state['values']['vars'] as $section => $value) {
    if (!is_array($value)) {
      variable_set($section, $value);
    }
    else {
      foreach ($value as $var => $val) {
        variable_set($var, $val);
      }
    }
  }
  
  cache_clear_all('ctools_export:views_view:recent_stories', 'cache_views');
  cache_clear_all('ctools_export:views_view:core_activities', 'cache_views');
  drupal_set_message(t('The configuration options have been saved.'));
}
