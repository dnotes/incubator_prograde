<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

function incubator_standard_theme_alpha_preprocess_block(&$vars) {
  if (in_array($vars['block']->region, array('header', 'menu', 'header_second', 'branding', 'footer'))) {
    $vars['title_attributes_array']['class'][] = 'element-invisible';
  }
}

function incubator_standard_theme_alpha_process_region(&$vars) {
  if ($vars['elements']['#region'] == 'content') {
    $theme = alpha_get_theme();
    $vars['main_menu'] = $theme->page['main_menu'];
    $vars['secondary_menu'] = $theme->page['secondary_menu'];
  }
}

function incubator_standard_theme_alpha_process_zone(&$vars) {
  if ($vars['elements']['#zone'] == 'content') {
    $theme = alpha_get_theme();
    $vars['tabs'] = $theme->page['tabs'];
  }
  elseif ($vars['elements']['#zone'] == 'header') {
    $theme = alpha_get_theme();
    $vars['header_banner_image_classes'] = str_replace('clearfix', '', implode(' ', $vars['content_attributes_array']['class']));
  }
}

function incubator_standard_theme_alpha_process_html(&$vars) {
  if (module_exists('color')) {
    _color_html_alter($vars);
  }
}

function incubator_standard_theme_alpha_process_page(&$vars) {
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
  foreach ($vars['main_menu'] as $key => $value) {
    $vars['main_menu'][$key]['html'] = TRUE;
    $vars['main_menu'][$key]['title'] = '<span>'. $vars['main_menu'][$key]['title'] .'</span>';
  }
}

function incubator_standard_theme_alpha_preprocess_node(&$vars) {
  $vars['submitted_day'] = format_date($vars['created'], 'custom', 'j');
  $vars['submitted_month'] = format_date($vars['created'], 'custom', 'M');
  $vars['submitted_year'] = format_date($vars['created'], 'custom', 'Y');
}

function incubator_standard_theme_form_system_theme_settings_alter(&$form, &$form_state) {
  if ($form['var']['#value'] == 'theme_incubator_standard_theme_settings') {
    $theme_settings = variable_get($form['var']['#value'], array());
    if (!empty($theme_settings['header_image']) && !empty($theme_settings['header_path'])) {
      $ext = preg_replace('/^[^\.]+\./', '', $theme_settings['header_path']);
      $path = file_create_url("public://header/header-mobile.$ext");
      $form['incubator_preview_image'] = array(
        '#type' => 'markup',
        '#markup' => '<style> #preview-header { background-image:url(' . $path . ') !important; } </style>',
      );
    }
    $form['show_alpha_settings'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show advanced layout settings'),
      '#default_value' => FALSE,
      '#weight' => 50,
    );
    $form['incubator_alpha_settings'] = array(
      '#type' => 'container',
      '#weight' => 50,
      '#states' => array(
        'invisible' => array(
          ':input[name="show_alpha_settings"]' => array('checked' => FALSE),
        ),
      ),
    );
    $form['incubator_alpha_settings']['alpha_settings'] = $form['alpha_settings'];
    unset($form['alpha_settings']);
  }
}
