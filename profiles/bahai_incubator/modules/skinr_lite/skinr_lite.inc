<?php
// $Id$

/**
 * @file
 *
 */



/**
 * Parse a skin_infos array as returned from a skins plugin.
 *
 * This function inserts any missing defaults and updates the stylesheet and
 * script paths to be relative to Drupal's root.
 *
 * @param $skin_infos
 *   An array of skins as returned from skin plugins.
 * @param $source
 *   An associative array containing information about the source of the skin.
 *   See skinr_implements() for details.
 *
 * @todo Merge into skinr_get_skin_info() and remove this function.
 */
function _skinr_lite_skin_info_process(&$skin_infos, $source) {
  foreach ($skin_infos as $skin_name => $skin_info) {
    // Populate default properties.
    $skin_infos[$skin_name] += array(
      'name' => '',
      'title' => '',
      'type' => 'checkboxes',
      'description' => '',
      'group' => 'general',
      'theme hooks' => array('*'),
      'attached' => array(),
      'options' => array(),
      'weight' => NULL,
      'default status' => 0,
      'status' => array(),
    );

    // Merge in name.
    $skin_infos[$skin_name]['name'] = $skin_name;

    // Merge in source information.
    $skin_infos[$skin_name]['source'] = $source;

    // Merge in default status for all themes.
    if (empty($skin_info['status'][$source{'name'}])) {
      $skin_infos[$skin_name]['status'][$source{'name'}] = $skin_infos[$skin_name]['default status'];
      if (!empty($skin_infos[$skin_name]['status'][$source{'base themes'}{0}])) {
        $skin_infos[$skin_name]['status'][$source{'name'}] |= $skin_infos[$skin_name]['status'][$source{'base themes'}{0}];
      }
    }

    // Add path to stylesheets.
    if (isset($skin_infos[$skin_name]['attached']['css'])) {
      _skinr_lite_add_path_to_files($skin_infos[$skin_name]['attached']['css'], $source['path']);
    }
    // Add path to scripts.
    if (isset($skin_infos[$skin_name]['attached']['js'])) {
      _skinr_lite_add_path_to_files($skin_infos[$skin_name]['attached']['js'], $source['path']);
    }

    foreach ($skin_infos[$skin_name]['options'] as $option_name => $option) {
      // Add path to stylesheets.
      if (isset($option['attached']['css'])) {
        _skinr_lite_add_path_to_files($skin_infos[$skin_name]['options'][$option_name]['attached']['css'], $source['path']);
      }
      // Add path to scripts.
      if (isset($option['attached']['js'])) {
        _skinr_lite_add_path_to_files($skin_infos[$skin_name]['options'][$option_name]['attached']['js'], $source['path']);
      }

      // Validate class by running it through drupal_html_class().
      if (!is_array($skin_infos[$skin_name]['options'][$option_name]['class'])) {
        $skin_infos[$skin_name]['options'][$option_name]['class'] = array($skin_infos[$skin_name]['options'][$option_name]['class']);
      }
      foreach ($skin_infos[$skin_name]['options'][$option_name]['class'] as $key => $class) {
        $skin_infos[$skin_name]['options'][$option_name]['class'][$key] = drupal_html_class($class);
      }
    }
  }
}


function skinr_lite_form_element($skin_info, $theme_settings = array()) {
  $field = FALSE;
  $name = $skin_info['name'];
  if (!empty($theme_settings['skins'][$name])) {
    $value = $theme_settings['skins'][$name];
  }
  switch ($skin_info['type']) {
    case 'checkboxes':
      $field = array(
        '#type' => 'checkboxes',
        '#multiple' => TRUE,
        '#title' => t($skin_info['title']),
        '#options' => skinr_lite_info_options_to_form_options($skin_info['options']),
        '#default_value' => isset($value) ? $value : array(),
        '#description' => t($skin_info['description']),
        '#weight' => isset($skin_info['weight']) ? $skin_info['weight'] : NULL,
        '#attributes' => array('class' => array('skinr-lite options checkboxes'), 'skinrlite' => $skin_info['name']),
      );
      break;
    case 'radios':
      $field = array(
        '#type' => 'radios',
        '#title' => t($skin_info['title']),
        '#options' => array_merge(array('' => '&lt;none&gt;'), skinr_lite_info_options_to_form_options($skin_info['options'])),
        '#default_value' => isset($value) ? $value : '',
        '#description' => t($skin_info['description']),
        '#weight' => isset($skin_info['weight']) ? $skin_info['weight'] : NULL,
        '#attributes' => array('class' => array('skinr-lite options radios'), 'skinrlite' => $skin_info['name']),
      );
      break;
    case 'select':
      $field = array(
        '#type' => 'select',
        '#title' => t($skin_info['title']),
        '#options' => array_merge(array('' => '<none>'), skinr_lite_info_options_to_form_options($skin_info['options'])),
        '#default_value' => isset($value) ? $value : '',
        '#description' => t($skin_info['description']),
        '#weight' => isset($skin_info['weight']) ? $skin_info['weight'] : NULL,
        '#attributes' => array('class' => array('skinr-lite select'), 'skinrlite' => $skin_info['name']),
      );
      break;
    default:
      // Raise an error.
      drupal_set_message(t("Widget %name's type is invalid.", array('%name' => $skin_name)), 'error', FALSE);
      break;
  }
  if (!empty($field)) {
    skinr_lite_attach_files($field, $skin_info);
  }
  return $field;
}

/**
 * Helper function to convert an array of options, as specified in the .info
 * file, into an array usable by Form API.
 *
 * @param $options
 *   An array containing at least the 'class' and 'label' keys.
 *
 * @return
 *   A Form API compatible array of options.
 *
 * @todo Rename function to be more descriptive.
 */
function skinr_lite_info_options_to_form_options($options) {
  $form_options = array();
  foreach ($options as $option_name => $option) {
    $form_options[$option_name] = t($option['title']);
  }
  return $form_options;
}


/**
 * Helper function to prepend a path to an array of stylesheet or script filenames.
 *
 * If the url is absolute (e.g. the url start with 'http://' or 'https://')
 * or relative to the site's root (e.g. the url starts with '/') the path does
 * not get prepended.
 *
 * @param $files
 *   A an array of filenames that need the path prepended.
 *   @todo Adjust docs to account for arrays instead of filenames.
 * @param $path
 *   The path to prepend.
 */
function _skinr_lite_add_path_to_files(&$files, $path) {
  $newfiles = array();
  foreach ($files as $data => $options) {
    if (!is_array($options)) {
      // $options is not an array, it's a filename and passed as first
      // (and only) argument.
      if (_skinr_lite_is_local_file($path . '/' . $options)) {
        $options = $path . '/' . $options;
      }
      $newfiles[] = $options;
    }
    elseif (is_numeric($data)) {
      // If $options is an array, but $data is not a filename, find $data in the
      // $options array.
      if (_skinr_lite_is_local_file($path . '/' . $options['data'])) {
        $options['data'] = $path . '/' . $options['data'];
      }
      $newfiles[] = $options;
    }
    else {
      if (_skinr_lite_is_local_file($path . '/' . $data)) {
        $data = $path . '/' . $data;
      }
      $newfiles[$data] = $options;
    }
  }
  $files = $newfiles;
}

/**
 * Helper function to determine whether or not a given file is local or not.
 */
function _skinr_lite_is_local_file($file) {
  if (strpos($file, 'http://') === 0 || strpos($file, 'https://') === 0 || strpos($file, '/') === 0) {
    return FALSE;
  }
  if (!file_exists($file)) {
    return FALSE;
  }
  return TRUE;
}
