<?php
// $Id$

/**
 * @file
 *
 */

function incubator_gallery_views_query_alter(&$view, &$query) {
  if ($view->base_table == 'node' &&
    !empty($view->display_handler->display->display_options['display_comment']) &&
    stripos($view->display_handler->display->display_options['display_comment'], 'require-gallery') !== FALSE) {
    foreach ($query->where as $id => $where) {
      if ($where['type'] == 'OR' && $where['conditions'][0]['operator'] == 'IS NOT NULL') {
        $query->add_where_expression($id, '(SELECT MAX(fdfgi.field_gallery_images_fid) AS gallery_image FROM {field_data_field_gallery_images} fdfgi WHERE fdfgi.revision_id = node.vid)');
      }
    }
  }
}
