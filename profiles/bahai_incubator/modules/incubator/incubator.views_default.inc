<?php
// $Id$

/**
 * @file
 *
 */

function incubator_views_default_views() {

  $view = new view();
  $view->name = 'recent_stories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Promoted Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = variable_get('incubator_recent_stories_title', 'Recent Stories');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = variable_get('incubator_recent_stories_count', 5);
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: List of teasers */
  $handler = $view->new_display('block', 'List of teasers', 'block');
  $handler->display->display_options['display_description'] = 'Node teasers arranged in a list';
  $handler->display->display_options['hide_admin_links'] = TRUE;

  /* Display: List of titles */
  $handler = $view->new_display('block', 'List of titles', 'block_titles');
  $handler->display->display_options['display_description'] = 'Node titles arranged in a simple list';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['hide_admin_links'] = TRUE;

  if (module_exists('views_slideshow_cycle')) {
    /* Display: Slideshow of teasers */
    $handler = $view->new_display('block', 'Slideshow (teasers)', 'block_slides');
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['css_class'] = variable_get('incubator_slideshows_controls_style', 'slideshows-controls-white');
    $handler->display->display_options['hide_admin_links'] = TRUE;
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = variable_get('incubator_recent_stories_count', 5);
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'slideshow';
    $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
    $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
    $handler->display->display_options['style_options']['skin_info'] = array(
      'class' => 'default',
      'name' => 'Default',
      'module' => 'views_slideshow',
      'path' => '',
      'stylesheets' => array(),
    );
    $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
    $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
    $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
    $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
    $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
    $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
    $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
    $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
    
    if ($position = variable_get('incubator_slideshows_pager', '')) {
      $handler->display->display_options['style_options']['widgets'][$position]['views_slideshow_pager']['enable'] = 1;
    }
    if ($position = variable_get('incubator_slideshows_controls', 'top')) {
      $handler->display->display_options['style_options']['widgets'][$position]['views_slideshow_controls']['enable'] = 1;
    }
    if ($position = variable_get('incubator_slideshows_counter', '')) {
      $handler->display->display_options['style_options']['widgets'][$position]['views_slideshow_slide_counter']['enable'] = 1;
    }
    
    $handler->display->display_options['style_options']['views_slideshow_cycle']['effect'] = variable_get('incubator_slideshows_effect', 'scrollHorz');
    $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
    $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = variable_get('incubator_slideshows_timeout', '5000');
    $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = variable_get('incubator_slideshows_speed', '700');
    $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = variable_get('incubator_slideshows_delay', '0');
    $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
    $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
    $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
    $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
    $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
    $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
    $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'node';
    $handler->display->display_options['row_options']['links'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;

    /* Display: Big Slideshow */
    $handler = $view->new_display('block', 'Slideshow (images)', 'block_bigslides');
    $handler->display->display_options['display_comment'] = 'require-gallery';
    $handler->display->display_options['css_class'] = variable_get('incubator_slideshows_controls_style', 'slideshows-controls-white');
    $handler->display->display_options['css_class'] = 'slideshow-controls-simple';
    $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
    $handler->display->display_options['hide_admin_links'] = TRUE;
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = variable_get('incubator_recent_stories_count', 5);
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'slideshow';
    $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
    $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
    $handler->display->display_options['style_options']['skin_info'] = array(
      'class' => 'default',
      'name' => 'Default',
      'module' => 'views_slideshow',
      'path' => '',
      'stylesheets' => array(),
    );
    $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
    $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
    $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
    $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
    $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
    $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
    $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
    $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
    if ($position = variable_get('incubator_slideshows_pager', '')) {
      $handler->display->display_options['style_options']['widgets'][$position]['views_slideshow_pager']['enable'] = 1;
    }
    if ($position = variable_get('incubator_slideshows_controls', 'top')) {
      $handler->display->display_options['style_options']['widgets'][$position]['views_slideshow_controls']['enable'] = 1;
    }
    if ($position = variable_get('incubator_slideshows_counter', '')) {
      $handler->display->display_options['style_options']['widgets'][$position]['views_slideshow_slide_counter']['enable'] = 1;
    }
    $handler->display->display_options['style_options']['views_slideshow_cycle']['effect'] = variable_get('incubator_slideshows_effect', 'scrollHorz');
    $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
    $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = variable_get('incubator_slideshows_timeout', '5000');
    $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = variable_get('incubator_slideshows_speed', '700');
    $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = variable_get('incubator_slideshows_delay', '0');
    $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
    $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
    $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
    $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
    $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
    $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
    $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Content: Nid */
    $handler->display->display_options['fields']['nid']['id'] = 'nid';
    $handler->display->display_options['fields']['nid']['table'] = 'node';
    $handler->display->display_options['fields']['nid']['field'] = 'nid';
    $handler->display->display_options['fields']['nid']['label'] = '';
    $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
    $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    /* Field: Content: Media */
    $handler->display->display_options['fields']['field_media']['id'] = 'field_media';
    $handler->display->display_options['fields']['field_media']['table'] = 'field_data_field_media';
    $handler->display->display_options['fields']['field_media']['field'] = 'field_media';
    $handler->display->display_options['fields']['field_media']['label'] = '';
    $handler->display->display_options['fields']['field_media']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['field_media']['alter']['path'] = 'node/[nid]';
    $handler->display->display_options['fields']['field_media']['alter']['absolute'] = TRUE;
    $handler->display->display_options['fields']['field_media']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_media']['hide_empty'] = TRUE;
    $handler->display->display_options['fields']['field_media']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_media']['type'] = 'file_rendered';
    $handler->display->display_options['fields']['field_media']['settings'] = array(
      'file_view_mode' => 'media_link',
    );
    /* Field: Content: Picture */
    $handler->display->display_options['fields']['field_gallery_images']['id'] = 'field_gallery_images';
    $handler->display->display_options['fields']['field_gallery_images']['table'] = 'field_data_field_gallery_images';
    $handler->display->display_options['fields']['field_gallery_images']['field'] = 'field_gallery_images';
    $handler->display->display_options['fields']['field_gallery_images']['label'] = '';
    $handler->display->display_options['fields']['field_gallery_images']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_gallery_images']['hide_empty'] = TRUE;
    $handler->display->display_options['fields']['field_gallery_images']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_gallery_images']['settings'] = array(
      'image_style' => 'slideshow',
      'image_link' => 'content',
    );
    $handler->display->display_options['fields']['field_gallery_images']['delta_limit'] = '1';
    $handler->display->display_options['fields']['field_gallery_images']['delta_offset'] = '0';
    $handler->display->display_options['fields']['field_gallery_images']['multi_type'] = 'ul';
    /* Field: Field: Main Image */
    $handler->display->display_options['fields']['field_main_image']['id'] = 'field_main_image';
    $handler->display->display_options['fields']['field_main_image']['table'] = 'field_data_field_main_image';
    $handler->display->display_options['fields']['field_main_image']['field'] = 'field_main_image';
    $handler->display->display_options['fields']['field_main_image']['label'] = '';
    $handler->display->display_options['fields']['field_main_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_main_image']['hide_empty'] = TRUE;
    $handler->display->display_options['fields']['field_main_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_main_image']['settings'] = array(
      'image_style' => 'slideshow',
      'image_link' => 'content',
    );
    $handler->display->display_options['defaults']['filter_groups'] = FALSE;
    $handler->display->display_options['filter_groups']['groups'] = array(
      1 => 'AND',
      2 => 'OR',
    );
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter criterion: Content: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: Content: Promoted to front page */
    $handler->display->display_options['filters']['promote']['id'] = 'promote';
    $handler->display->display_options['filters']['promote']['table'] = 'node';
    $handler->display->display_options['filters']['promote']['field'] = 'promote';
    $handler->display->display_options['filters']['promote']['value'] = '1';
    $handler->display->display_options['filters']['promote']['group'] = 1;
    if (module_exists('incubator_video')) {
      /* Filter criterion: Content: Media (field_media:fid) */
      $handler->display->display_options['filters']['field_media_fid']['id'] = 'field_media_fid';
      $handler->display->display_options['filters']['field_media_fid']['table'] = 'field_data_field_media';
      $handler->display->display_options['filters']['field_media_fid']['field'] = 'field_media_fid';
      $handler->display->display_options['filters']['field_media_fid']['operator'] = 'not empty';
      $handler->display->display_options['filters']['field_media_fid']['group'] = 2;
    }
    /* Filter criterion: Field: Main Image (field_main_image:fid) */
    $handler->display->display_options['filters']['field_main_image_fid']['id'] = 'field_main_image_fid';
    $handler->display->display_options['filters']['field_main_image_fid']['table'] = 'field_data_field_main_image';
    $handler->display->display_options['filters']['field_main_image_fid']['field'] = 'field_main_image_fid';
    $handler->display->display_options['filters']['field_main_image_fid']['operator'] = 'not empty';
    $handler->display->display_options['filters']['field_main_image_fid']['group'] = 2;
  }
  
  $translatables['recent_stories'] = array(
    t('Master'),
    t('Promoted Content'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('List of teasers'),
    t('Node teasers arranged in a list'),
    t('List of titles'),
    t('Node titles arranged in a simple list'),
    t('Slideshow (teasers)'),
    t('Slideshow (images)'),
  );
  $views[$view->name] = $view;

  return $views;
}
