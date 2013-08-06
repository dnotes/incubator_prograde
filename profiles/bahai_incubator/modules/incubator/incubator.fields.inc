<?php
// $Id$

/**
 * @file
 *
 */

function _incubator_fields_field_main_image($op = 'field') {
  $t = get_t();

  // FIELD
  if ($op == 'field') {
    $field = array(
      'field_name' => 'field_main_image',
      'type' => 'image',
      'locked' => '0',
      'cardinality' => '1',
      'indexes' => array('fid' => array('fid')),
      'translatable' => '0',
      'settings' => array(
        'uri_scheme' => 'public',
        'default_image' => 0,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
    );
    return $field;
  }

  // FIELD INSTANCE
  elseif ($op == 'instance') {

    // determine the widget to use
    if (module_exists('media')) {
      $widget = array(
        'weight' => '1',
        'type' => 'media_generic',
        'module' => 'media',
        'active' => 1,
        'settings' => array(
          'allowed_types' => array(
            'image' => 'image',
            'audio' => 0,
            'video' => 0,
            'default' => 0,
          ),
          'allowed_schemes' => array(
            'public' => 'public',
            'private' => 'private',
            'youtube' => 0,
          ),
          'progress_indicator' => 'throbber',
          'preview_image_style' => 'thumbnail',
        ),
      );
    }
    else {
      $widget = array(
        'weight' => '32',
        'type' => 'image_image',
        'module' => 'image',
        'active' => 1,
        'settings' => array(
          'progress_indicator' => 'throbber',
          'preview_image_style' => 'thumbnail',
        ),
      );
    }

    if (module_exists('colorbox')) {
      $display_default = array(
        'label' => 'hidden',
        'type' => 'colorbox',
        'weight' => '-50',
        'settings' => array(
          'colorbox_node_style' => 'medium',
          'colorbox_image_style' => 'large',
          'colorbox_gallery' => 'page',
          'colorbox_gallery_custom' => '',
          'colorbox_caption' => 'auto',
        ),
        'module' => 'colorbox',
      );
    }
    else {
      $display_default = array(
        'label' => 'hidden',
        'type' => 'image',
        'weight' => '-50',
        'settings' => array(
          'image_style' => 'medium',
          'image_link' => '',
        ),
        'module' => 'image',
      );
    }
    
    return array(
      'label' => 'Main Image',
      'widget' => $widget,
      'settings' => array(
        'file_directory' => 'images',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '10 MB',
        'max_resolution' => '',
        'min_resolution' => '',
        'alt_field' => 0,
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'display' => array(
        'default' => $display_default,
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'image',
          'weight' => '-50',
          'settings' => array(
            'image_style' => 'thumbnail',
            'image_link' => 'content',
          ),
          'module' => 'image',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'type' => 'image',
          'weight' => '-50',
          'settings' => array(
            'image_style' => 'thumbnail',
            'image_link' => 'content',
          ),
          'module' => 'image',
        ),
        'rss' => array(
          'label' => 'hidden',
          'type' => 'image',
          'weight' => '-50',
          'settings' => array(
            'image_style' => 'medium',
            'image_link' => '',
          ),
          'module' => 'image',
        ),
      ),
      'description' => $t('The main image that represents this content'),
    );
    return $instance;
  }
  return FALSE;
}

function _incubator_fields_field_tags($op = 'field') {
  $t = get_t();

  if ($voc = taxonomy_vocabulary_machine_name_load('tags')) {

    // FIELD DEFINITION
    if ($op == 'field') {
      $field = array(
        'type' => 'taxonomy_term_reference',
        // Set cardinality to unlimited for tagging.
        'cardinality' => FIELD_CARDINALITY_UNLIMITED,
        'settings' => array(
          'allowed_values' => array(
            array(
              'vocabulary' => 'tags',
              'parent' => 0,
            ),
          ),
        ),
      );
      return $field;
    }

    // FIELD INSTANCE DEFINITION
    elseif ($op == 'instance') {
      $instance = array(
        'entity_type' => 'node',
        'label' => 'Tags',
        'bundle' => 'page',
        'description' => $t('Enter a comma-separated list of words to describe your content.'),
        'widget' => array(
          'type' => 'taxonomy_autocomplete',
          'weight' => -4,
        ),
        'display' => array(
          'default' => array(
            'type' => 'taxonomy_term_reference_link',
            'weight' => 50,
          ),
        ),
      );
      return $instance;
    }

  }
  return FALSE;
}

// _incubator_fields_field_core_activities is in incubator_core_activities.module

// _incubator_fields_field_localities is in incubator_localities module

// For event types

function _incubator_fields_field_event_info($op = 'field') {
  $t = get_t();

  // FIELD DEFINITION
  if ($op == 'field') {
    $field = array(
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
      'indexes' => array(
        'format' => array(
          'format',
        ),
      ),
      'type' => 'text_long',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
    );
    return $field;
  }

  // FIELD INSTANCE DEFINITION
  elseif ($op == 'instance') {
    $instance = array(
      'label' => $t('Time and place'),
      'widget' => array(
        'weight' => '32',
        'type' => 'text_textarea',
        'module' => 'text',
        'active' => 1,
        'settings' => array(
          'rows' => '2',
        ),
      ),
      'settings' => array(
        'text_processing' => '0',
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'text_default',
          'weight' => '-20',
          'settings' => array(),
          'module' => 'text',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'text_default',
          'weight' => '-20',
          'settings' => array(),
          'module' => 'text',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'type' => 'text_default',
          'weight' => '-20',
          'settings' => array(),
          'module' => 'text',
        ),
      ),
      'required' => 1,
      'description' => $t('a brief, human-readable description of the time and place, e.g. "every Tuesday from 7 to 9pm in Albany"'),
      'default_value' => NULL,
    );
    return $instance;
  }

  return FALSE;
}

function _incubator_fields_field_event_date($op = 'field') {
  $t = get_t();

  // FIELD DEFINITION
  if ($op == 'field') {
    $field = array(
      'settings' => array(
        'repeat' => '1',
        'granularity' => array(
          'month' => 'month',
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'year' => 'year',
          'second' => 0,
        ),
        'tz_handling' => 'site',
        'timezone_db' => 'UTC',
        'todate' => 'optional',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
      'indexes' => array(),
      'type' => 'datestamp',
      'module' => 'date',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
    );
    return $field;
  }

  // FIELD INSTANCE DEFINITION
  elseif ($op == 'instance') {
    $instance = array(
      'label' => $t('Event date'),
      'widget' => array(
        'weight' => '33',
        'type' => 'date_popup',
        'module' => 'date',
        'active' => 1,
        'settings' => array(
          'input_format' => 'm/d/Y - g:i:sa',
          'input_format_custom' => '',
          'year_range' => '-0:+3',
          'increment' => '15',
          'label_position' => 'above',
          'text_parts' => array(),
          'repeat_collapsed' => '1',
        ),
      ),
      'settings' => array(
        'default_value' => 'now',
        'default_value_code' => '',
        'default_value2' => 'blank',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'display' => array(
        'default' => array(
          'label' => 'above',
          'type' => 'date_default',
          'weight' => '50',
          'settings' => array(
            'format_type' => 'medium',
            'fromto' => 'value',
            'multiple_number' => '',
            'multiple_from' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'hide',
          ),
          'module' => 'date',
        ),
      ),
      'required' => 0,
      'description' => '',
    );
    return $instance;
  }

  return FALSE;
}

function _incubator_fields_field_activity_group($op = 'field') {
  $t = get_t();

  if ($voc = taxonomy_vocabulary_machine_name_load('activity_group')) {

    // FIELD DEFINITION
    if ($op == 'field') {
      $field = array(
        'settings' => array(
          'allowed_values' => array(
            array(
              'vocabulary' => 'activity_group',
              'parent' => '0',
            ),
          ),
        ),
        'storage' => array(
          'type' => 'field_sql_storage',
          'settings' => array(),
        ),
        'indexes' => array(
          'tid' => array(
            'tid',
          ),
        ),
        'type' => 'taxonomy_term_reference',
        'module' => 'taxonomy',
        'active' => '1',
        'locked' => '0',
        'cardinality' => '-1',
      );
      return $field;
    }

    // FIELD INSTANCE DEFINITION
    elseif ($op == 'instance') {
      $instance = array(
        'label' => $t('Groups'),
        'widget' => array(
          'weight' => '34',
          'type' => 'options_buttons',
          'module' => 'options',
          'active' => 1,
          'settings' => array(),
        ),
        'settings' => array(),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'taxonomy_term_reference_link',
            'settings' => array(),
            'module' => 'taxonomy',
            'weight' => 11,
          ),
        ),
        'required' => 0,
        'description' => $t('Choose one or more groups if appropriate.'),
        'default_value' => NULL,
      );
      return $instance;
    }

  }
  return FALSE;
}

// For announcements

function _incubator_fields_field_expires_date($op = 'field') {
  $t = get_t();

  // FIELD DEFINITION
  if ($op == 'field') {
    $field = array(
      'settings' => array(
        'repeat' => 0,
        'granularity' => array(
          'month' => 'month',
          'day' => 'day',
          'year' => 'year',
          'hour' => 0,
          'minute' => 0,
          'second' => 0,
        ),
        'tz_handling' => 'none',
        'timezone_db' => '',
        'todate' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
      'type' => 'datestamp',
      'module' => 'date',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
    );
    return $field;
  }

  // FIELD INSTANCE DEFINITION
  elseif ($op == 'instance') {
    $instance = array(
      'label' => $t('Expires'),
      'widget' => array(
        'weight' => '32',
        'type' => 'date_popup',
        'module' => 'date',
        'active' => 1,
        'settings' => array(
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'year_range' => '-3:+3',
          'increment' => 15,
          'label_position' => 'above',
          'text_parts' => array(),
          'repeat_collapsed' => 0,
        ),
      ),
      'settings' => array(
        'default_value' => 'strtotime',
        'default_value_code' => '+1 week',
        'default_value2' => 'blank',
        'default_value_code2' => '',
      ),
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'type' => 'date_default',
          'weight' => '1',
          'settings' => array(
            'format_type' => 'medium',
            'fromto' => 'both',
            'multiple_number' => '',
            'multiple_from' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'module' => 'date',
        ),
      ),
      'required' => 1,
      'description' => $t('The date that the announcement expires'),
    );
    return $instance;
  }

  return FALSE;
}

// For users

function _incubator_fields_field_realname($op = 'field') {
  $t = get_t();

  // FIELD DEFINITION
  if ($op == 'field') {
    $field = array(
      'translatable' => '0',
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
      'indexes' => array(
        'format' => array(
          'format',
        ),
      ),
      'field_name' => 'field_realname',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
    );
    return $field;
  }

  // FIELD INSTANCE DEFINITION
  elseif ($op == 'instance') {
    $instance = array(
      'label' => $t('Real name'),
      'widget' => array(
        'weight' => '-50',
        'type' => 'text_textfield',
        'module' => 'text',
        'active' => 1,
        'settings' => array(
          'size' => '60',
        ),
      ),
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => 1,
      ),
      'display' => array(
        'default' => array(
          'label' => 'above',
          'type' => 'hidden',
          'weight' => '-50',
          'settings' => array(),
        ),
      ),
      'required' => 1,
      'description' => $t('This site will use your real name for display in public areas of the site.  Please use the name by which you are known in public.'),
      'default_value' => NULL,
    );
    return $instance;
  }

  return FALSE;
}

//function _incubator_fields_field_FIELDNAME($op = 'field') {
//  $t = get_t();
//
//  // FIELD DEFINITION
//  if ($op == 'field') {
//    $field = array(
//
//    );
//    return $field;
//  }
//
//  // FIELD INSTANCE DEFINITION
//  elseif ($op == 'instance') {
//    $instance = array(
//
//    );
//    return $instance;
//  }
//
//  return FALSE;
//}
