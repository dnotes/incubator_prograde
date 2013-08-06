<?php
// $Id$

/**
 * @file bahai_incubator.profile
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function bahai_incubator_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  $form['site_information']['site_mail']['#default_value'] = st('no-reply@', array(), array('context' => 'Email address name')) . $_SERVER['SERVER_NAME'];
}
