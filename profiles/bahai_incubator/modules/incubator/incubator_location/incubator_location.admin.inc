<?php
// $Id$

/**
 * @file
 *
 */

function incubator_location_incubator_settings_menu() {
  return array(
    'description' => 'Set the default location for the site.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('location_chooser_location_form'),
    'file' => 'location_chooser.admin.inc',
    'file path' => drupal_get_path('module', 'location_chooser'),
  );
}

/**
 * Implements hook_incubator_settings().
 */
function incubator_location_incubator_settings() {}