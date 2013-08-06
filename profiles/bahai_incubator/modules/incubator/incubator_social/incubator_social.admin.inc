<?php

/**
 * @file
 *
 */

function incubator_social_incubator_settings_menu() {
  return array(
    'description' => 'Settings for social site integration.',
    'title' => 'Social Integration',
  );
}

function incubator_social_incubator_settings() {
  
  $form = $form_state = array();
  
  module_load_include('inc', 'hybridauth', 'hybridauth.admin');
  
  foreach(incubator_social_preferred_providers() as $provider_id) {
    $keys_form = hybridauth_admin_provider_settings($form, $form_state, $provider_id);
    $enabled = variable_get("hybridauth_provider_{$provider_id}_enabled", FALSE);
    $form['keys'][$provider_id] = $keys_form['keys'];
    $form['keys'][$provider_id]['#title'] = $provider_id . ($enabled ? ' <span class="provider-enabled">' . t('Enabled') . '</span>' : '');
    $form['keys'][$provider_id]['#collapsible'] = TRUE;
    $form['keys'][$provider_id]['#collapsed'] = TRUE;
  }
  
  $form = system_settings_form($form);
  $form['#submit'][] = 'incubator_social_incubator_settings_submit';
  drupal_add_css('.provider-enabled{background-color:green;color:white;padding:1px 5px;}', array('type' => 'inline'));
  
  return $form;
  
}

function incubator_social_incubator_settings_submit(&$form, &$form_state) {
  foreach(incubator_social_preferred_providers() as $provider_id) {
    if ($form_state['values']["hybridauth_provider_{$provider_id}_keys_secret"] && (
        $form_state['values']["hybridauth_provider_{$provider_id}_keys_id"] ||
        $form_state['values']["hybridauth_provider_{$provider_id}_keys_key"]
      )) {
      variable_set("hybridauth_provider_{$provider_id}_enabled", TRUE);
    }
    else {
      variable_set("hybridauth_provider_{$provider_id}_enabled", FALSE);
    }
  }
}
