<?php
// $Id$

/**
 * @file
 *
 */

/**
 * Implements hook_views_query_alter().
 *
 * This function sorts the communities by taxonomy heirarchy and weight, so that
 * administrators may order the taxonomy to put neighborhoods in cities, etc.
 */
function incubator_localities_views_query_alter(&$view, &$query) {
  if ($view->name == 'localities') {
    $query->fields['taxonomy_orderby'] = array(
      'field' => "IFNULL(CONCAT(LPAD(taxonomy_term_data_taxonomy_term_hierarchy.weight, 3, 0), '.', LPAD(taxonomy_term_data.weight, 3, 0)), LPAD(taxonomy_term_data.weight, 3, 0))",
      'alias' => 'taxonomy_orderby',
    );
    if (variable_get('incubator_localities_custom_sorted', FALSE)) {
      array_unshift($query->orderby, array(
        'field' => 'taxonomy_orderby',
        'direction' => 'ASC',
      ));
    }
  }
}
