<?php
// $Id$

/**
 * @file
 *
 */

function incubator_facilities_views_data_alter(&$data) {
  $data['location']['lid']['argument'] = array(
    'handler' => 'views_handler_argument_numeric',
  );
}
