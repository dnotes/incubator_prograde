<?php
// $Id$

/**
 * @file
 *
 */

function incubator_news_incubator_settings_menu() {
  return array('description' => 'Settings for news reporting and pages.');
}

function incubator_news_incubator_settings() {
  $form['incubator_news_title'] = array(
    '#type' => 'textfield',
    '#title' => t('News page title'),
    '#default_value' => variable_get('incubator_news_title', "Local Bahá'í News"),
  );

  cache_clear_all('ctools_export:views_view:news', 'cache_views');
  return system_settings_form($form);
}