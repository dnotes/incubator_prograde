<?php
// $Id$

/**
 * @file
 *
 */

function incubator_mapping_incubator_settings_menu() {
  return array('description' => 'Settings for maps provided by the Incubator.');
}

function incubator_mapping_incubator_settings($form_state) {
//  ctools_include('dependent');
  include_once drupal_get_path('module', 'openlayers') . '/modules/openlayers_ui/openlayers_ui.module';
  include_once drupal_get_path('module', 'openlayers') . '/modules/openlayers_ui/includes/openlayers_ui.maps.inc';
  drupal_add_js(drupal_get_path('module', 'openlayers') . '/modules/openlayers_ui/js/openlayers_ui.maps.js');
  drupal_add_css(drupal_get_path('module', 'openlayers') . '/modules/openlayers_ui/openlayers_ui.css');
  
  // Pass variables etc. to javascript
  $pass_values = array(
    'openlayersForm' => array(
      'projectionLayers' => openlayers_ui_get_projection_options(),
    ),
  );
  drupal_add_js($pass_values, 'setting');

  $projection = openlayers_get_projection('EPSG', '3857');
  openlayers_add_js_projection_definition($projection);

  // centerpoint & zoom of this map are overridden
  // by the mapformvalues behavior on page load.
  //
  // Note that navigation screws up the boxselect
  // behavior for getting extent.
  $centermap_def = array(
    'id' => 'openlayers-center-helpmap',
    'projection' => $projection->identifier,
    'displayProjection' => $projection->identifier,
    'default_layer' => 'mapquest_osm',
    'width' => '600px',
    'height' => '400px',
    'center' => array(
      'initial' => array(
        'centerpoint' => "0, 0",
        'zoom' => 2,
      ),
    ),
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'layers' => array(
      'mapquest_osm',
    ),
    'behaviors' => array(
      'openlayers_behavior_navigation' => array(),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_dragpan' => array(),
      'openlayers_behavior_mapformvalues' => array(),
      'openlayers_behavior_attribution' => array(),
    ),
  );
  

  $title = t('Incubator map settings');
  $description = t('Set the map position and zoom defaults on the map above.');
  $form['helpmap'] = array(
    '#markup' => "<h3>$title</h3>" .
    '<div class="form-item openlayers-center-helpmap" style="display:block">' .
    openlayers_render_map_data($centermap_def) .
    '<div class="description">'. $description . '</div></div>'
  );
  $form['incubator_mapping_centerpoint'] = array(
    '#type' => 'hidden',
    '#default_value' => variable_get('incubator_mapping_centerpoint', '-99, 39'),
    '#attributes' => array('class' => array('openlayers-form-centerpoint'), 'id' => 'edit-center-initial-centerpoint'),
  );
  $form['incubator_mapping_zoom'] = array(
    '#type' => 'hidden',
    '#default_value' => variable_get('incubator_mapping_zoom', '4'),
    '#attributes' => array('class' => array('openlayers-form-zoom'), 'id' => 'edit-center-initial-zoom'),
  );
  
//  $form['restrict'] = array(
//    '#type' => 'fieldset',
//    '#title' => t('Restrict Extent')
//  );
//  $form['restrict']['incubator_mapping_restrict_extent'] = array(
//    '#type' => 'checkbox',
//    '#title' => t('Restrict Extent'),
//    '#description' => t('Setting the restricted extent of a map prevents users
//      from panning the map outside a specified area. This can be set
//      interactively by holding the shift key and dragging a box over the map
//      above. Setting the extent does not restrict how far users can zoom out,
//      so setting restricted zoom levels (via individual layer settings) is
//      recommended.'),
//    '#id' => 'restrictextent',
//    '#default_value' => variable_get('incubator_mapping_restrict_extent', FALSE),
//  );
//  $form['restrict']['incubator_mapping_restricted_extent'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Restricted Extent'),
//    '#description' => t('Prevents users from panning outside of a specific bounding box'),
//    '#default_value' => variable_get('incubator_mapping_restrict_extent', ''),
//    '#attributes' => array('class' => array('openlayers-form-restrictedExtent')),
//    '#size' => 25,
//    '#process' => array('ctools_dependent_process'),
//    '#dependency' => array('restrictextent' => array(1))
//  );
  return system_settings_form($form);
}
