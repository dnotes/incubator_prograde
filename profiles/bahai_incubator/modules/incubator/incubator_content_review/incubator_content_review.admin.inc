<?php
// $Id$

/**
 * @file
 *
 */

function incubator_content_review_incubator_settings_menu() {
  return array(
    'description' => 'Settings for content review and moderation.',
    'title' => 'Editing workflow',
  );
}

function incubator_content_review_incubator_settings() {
  
  // A list of content types to review
  foreach (node_type_get_types() as $name => $type) {
    $options[$type->type] = check_plain($type->name);
    $defaults[$type->type] = in_array('moderation', variable_get("node_options_$type->type", array())) ? $type->type : FALSE;
  }
  $form['incubator_content_review_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types to moderate'),
    '#options' => $options,
    '#default_value' => $defaults,
  );
  
  $form['#submit'][] = 'incubator_content_review_admin_form_submit';            // this must be before the system form submit function
  $form = system_settings_form($form);                                       // we don't yet need a system settings form for this

  return $form;
}

function incubator_content_review_admin_form_submit(&$form, &$form_state) {
  foreach ($form_state['values']['incubator_content_review_types'] as $type => $value) {
    $node_options = variable_get("node_options_$type", array());
    if (empty($value) && in_array('moderation', $node_options)) {
      $node_options = array_diff($node_options, array('moderation'));
    }
    elseif (!empty($value) && !in_array('moderation', $node_options)) {
      $node_options[] = 'moderation';
    }
    variable_set("node_options_$type", $node_options);
  }
  unset($form_state['values']['incubator_content_review_types']);
}
