<?php
// $Id$

/**
 * @file
 *
 */

function incubator_content_review_views_default_views_alter(&$views) {
  $views['workbench_edited']->disabled = TRUE;
  $views['workbench_recent_content']->disabled = TRUE;
}
