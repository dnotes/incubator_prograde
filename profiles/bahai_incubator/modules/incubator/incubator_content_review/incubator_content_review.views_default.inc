<?php
// $Id$

/**
 * @file
 *
 */

function incubator_content_review_views_default_views() {
  
/*******************************************************************************
 *******************************************************************************
 * AUTHOR VIEW
 *******************************************************************************
 ******************************************************************************/  

$view = new view();
$view->name = 'incubator_workbench_author';
$view->description = 'Lists content by moderation state.';
$view->tag = 'Workbench Moderation';
$view->base_table = 'node_revision';
$view->human_name = 'Workbench Author - Incubator';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'My content';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'view all';
$handler->display->display_options['link_display'] = 'content_by_me_page';
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  2 => '2',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'nid' => 'nid',
  'log' => 'log',
  'workbench_moderation_history_link' => 'workbench_moderation_history_link',
  'moderation_actions' => 'moderation_actions',
  'status' => 'status',
  'state' => 'state',
  'title' => 'title',
  'type' => 'type',
  'name_1' => 'name_1',
  'name' => 'name',
  'changed' => 'changed',
);
$handler->display->display_options['style_options']['default'] = 'changed';
$handler->display->display_options['style_options']['info'] = array(
  'nid' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'log' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'workbench_moderation_history_link' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'moderation_actions' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'status' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'state' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'changed' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['content'] = 'You haven\'t created or edited any content.';
$handler->display->display_options['empty']['area']['format'] = '1';
/* Relationship: Workbench Moderation: Node */
$handler->display->display_options['relationships']['nid']['id'] = 'nid';
$handler->display->display_options['relationships']['nid']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['relationships']['nid']['field'] = 'nid';
$handler->display->display_options['relationships']['nid']['required'] = TRUE;
/* Relationship: Content revision: User */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Relationship: Content: Author */
$handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
$handler->display->display_options['relationships']['uid_1']['table'] = 'node';
$handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
$handler->display->display_options['relationships']['uid_1']['relationship'] = 'nid';
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['relationship'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content revision: Log message */
$handler->display->display_options['fields']['log']['id'] = 'log';
$handler->display->display_options['fields']['log']['table'] = 'node_revision';
$handler->display->display_options['fields']['log']['field'] = 'log';
$handler->display->display_options['fields']['log']['exclude'] = TRUE;
$handler->display->display_options['fields']['log']['alter']['text'] = '<br/>[log]';
$handler->display->display_options['fields']['log']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['log']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation history link */
$handler->display->display_options['fields']['workbench_moderation_history_link']['id'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['table'] = 'node';
$handler->display->display_options['fields']['workbench_moderation_history_link']['field'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['relationship'] = 'nid';
$handler->display->display_options['fields']['workbench_moderation_history_link']['exclude'] = TRUE;
$handler->display->display_options['fields']['workbench_moderation_history_link']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation links */
$handler->display->display_options['fields']['moderation_actions']['id'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['moderation_actions']['field'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['label'] = 'Set moderation state';
$handler->display->display_options['fields']['moderation_actions']['exclude'] = TRUE;
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['relationship'] = 'nid';
$handler->display->display_options['fields']['status']['exclude'] = TRUE;
$handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['status']['type'] = 'true-false';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Workbench Moderation: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['state']['field'] = 'state';
$handler->display->display_options['fields']['state']['exclude'] = TRUE;
$handler->display->display_options['fields']['state']['machine_name'] = 0;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'nid';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<a href="/node/[nid]">[title]</a> 
<span class="status new [status] [state]">New [state]</span>
<span class="status revision [status] [state]">Revision [state]</span> 
<a class="node-edit-link" href="/node/[nid]/edit?destination=admin/workbench">(edit)</a>
<br/>
<span class="log-message">[log]</span>
[moderation_actions]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['relationship'] = 'nid';
$handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
$handler->display->display_options['fields']['name_1']['table'] = 'users';
$handler->display->display_options['fields']['name_1']['field'] = 'name';
$handler->display->display_options['fields']['name_1']['relationship'] = 'uid_1';
$handler->display->display_options['fields']['name_1']['label'] = 'Author';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Revised by';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['relationship'] = 'nid';
$handler->display->display_options['fields']['changed']['label'] = 'Last updated';
$handler->display->display_options['fields']['changed']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['changed']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
$handler->display->display_options['fields']['changed']['custom_date_format'] = '1';
$handler->display->display_options['fields']['changed']['format_date_sql'] = 0;
/* Sort criterion: Content: Updated date */
$handler->display->display_options['sorts']['changed']['id'] = 'changed';
$handler->display->display_options['sorts']['changed']['table'] = 'node';
$handler->display->display_options['sorts']['changed']['field'] = 'changed';
$handler->display->display_options['sorts']['changed']['relationship'] = 'nid';
$handler->display->display_options['sorts']['changed']['order'] = 'DESC';
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['relationship'] = 'nid';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  7 => 0,
  8 => 0,
  3 => 0,
  6 => 0,
  4 => 0,
  5 => 0,
  9 => 0,
  10 => 0,
);
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'nid';
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  7 => 0,
  8 => 0,
  3 => 0,
  6 => 0,
  4 => 0,
  5 => 0,
  9 => 0,
  10 => 0,
);
/* Filter criterion: Workbench Moderation: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'draft' => 'draft',
  'needs_review' => 'needs_review',
  'published' => 'published',
);
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  7 => 0,
  8 => 0,
  3 => 0,
  6 => 0,
  4 => 0,
  5 => 0,
  9 => 0,
  10 => 0,
);
/* Filter criterion: Workbench Moderation: Current */
$handler->display->display_options['filters']['current']['id'] = 'current';
$handler->display->display_options['filters']['current']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['current']['field'] = 'current';
$handler->display->display_options['filters']['current']['value'] = '1';
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'uid_1';
$handler->display->display_options['filters']['uid_current']['value'] = '1';

/* Display: Needs review block */
$handler = $view->new_display('block', 'Needs review block', 'needs_review_block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'For review';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'This list displays your content in the "Needs review" state. Currently there is no such content.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['relationship'] = 'nid';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'nid';
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
/* Filter criterion: Workbench Moderation: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'needs_review' => 'needs_review',
);
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  7 => 0,
  8 => 0,
  3 => 0,
  6 => 0,
  4 => 0,
  5 => 0,
  9 => 0,
  10 => 0,
);
/* Filter criterion: Workbench Moderation: Current */
$handler->display->display_options['filters']['current']['id'] = 'current';
$handler->display->display_options['filters']['current']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['current']['field'] = 'current';
$handler->display->display_options['filters']['current']['value'] = '1';
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'uid_1';
$handler->display->display_options['filters']['uid_current']['value'] = '1';

/* Display: Drafts block */
$handler = $view->new_display('block', 'Drafts block', 'recent_drafts_block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Drafts';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['link_url'] = '//admin/workbench/content/editor/state/?title=&type=All&state[]=draft';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'This list displays your content in the "Draft" state. Currently there is no such content.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['relationship'] = 'nid';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'nid';
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
/* Filter criterion: Workbench Moderation: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'draft' => 'draft',
);
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  7 => 0,
  8 => 0,
  3 => 0,
  6 => 0,
  4 => 0,
  5 => 0,
  9 => 0,
  10 => 0,
);
/* Filter criterion: Workbench Moderation: Current */
$handler->display->display_options['filters']['current']['id'] = 'current';
$handler->display->display_options['filters']['current']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['current']['field'] = 'current';
$handler->display->display_options['filters']['current']['value'] = '1';
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'uid_1';
$handler->display->display_options['filters']['uid_current']['value'] = '1';

/* Display: Content by me block */
$handler = $view->new_display('block', 'Content by me block', 'content_by_me_block');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = TRUE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'view all';
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'content_by_me_page';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'You have not created any content.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['empty']['area']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['relationship'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['relationship'] = 'nid';
$handler->display->display_options['fields']['type']['exclude'] = TRUE;
$handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
/* Field: Content revision: Log message */
$handler->display->display_options['fields']['log']['id'] = 'log';
$handler->display->display_options['fields']['log']['table'] = 'node_revision';
$handler->display->display_options['fields']['log']['field'] = 'log';
$handler->display->display_options['fields']['log']['exclude'] = TRUE;
$handler->display->display_options['fields']['log']['alter']['text'] = '<br/>[log]';
$handler->display->display_options['fields']['log']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['log']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation history link */
$handler->display->display_options['fields']['workbench_moderation_history_link']['id'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['table'] = 'node';
$handler->display->display_options['fields']['workbench_moderation_history_link']['field'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['relationship'] = 'nid';
$handler->display->display_options['fields']['workbench_moderation_history_link']['exclude'] = TRUE;
$handler->display->display_options['fields']['workbench_moderation_history_link']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation links */
$handler->display->display_options['fields']['moderation_actions']['id'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['moderation_actions']['field'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['label'] = 'Set moderation state';
$handler->display->display_options['fields']['moderation_actions']['exclude'] = TRUE;
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['relationship'] = 'nid';
$handler->display->display_options['fields']['status']['exclude'] = TRUE;
$handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['status']['type'] = 'true-false';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Workbench Moderation: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['state']['field'] = 'state';
$handler->display->display_options['fields']['state']['exclude'] = TRUE;
$handler->display->display_options['fields']['state']['machine_name'] = 0;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'nid';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<span class="node-type">[type] : </span>
<a href="/node/[nid]">[title]</a> 
<span class="status new [status] [state]">New [state]</span>
<span class="status revision [status] [state]">Revision [state]</span> 
<a class="node-edit-link" href="/node/[nid]/edit?destination=admin/workbench">(edit)</a>
<br/>
<span class="log-message">[log]</span>
[moderation_actions]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Revised by';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['relationship'] = 'nid';
$handler->display->display_options['fields']['changed']['label'] = 'Last updated';
$handler->display->display_options['fields']['changed']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['changed']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
$handler->display->display_options['fields']['changed']['custom_date_format'] = '1';
$handler->display->display_options['fields']['changed']['format_date_sql'] = 0;

/* Display: Content by me page */
$handler = $view->new_display('page', 'Content by me page', 'content_by_me_page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 25, 50, 100';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'You have not created any content.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['empty']['area']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['relationship'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content revision: Log message */
$handler->display->display_options['fields']['log']['id'] = 'log';
$handler->display->display_options['fields']['log']['table'] = 'node_revision';
$handler->display->display_options['fields']['log']['field'] = 'log';
$handler->display->display_options['fields']['log']['exclude'] = TRUE;
$handler->display->display_options['fields']['log']['alter']['text'] = '<br/>[log]';
$handler->display->display_options['fields']['log']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['log']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation history link */
$handler->display->display_options['fields']['workbench_moderation_history_link']['id'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['table'] = 'node';
$handler->display->display_options['fields']['workbench_moderation_history_link']['field'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['relationship'] = 'nid';
$handler->display->display_options['fields']['workbench_moderation_history_link']['exclude'] = TRUE;
$handler->display->display_options['fields']['workbench_moderation_history_link']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation links */
$handler->display->display_options['fields']['moderation_actions']['id'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['moderation_actions']['field'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['label'] = 'Set moderation state';
$handler->display->display_options['fields']['moderation_actions']['exclude'] = TRUE;
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['relationship'] = 'nid';
$handler->display->display_options['fields']['status']['exclude'] = TRUE;
$handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['status']['type'] = 'true-false';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Workbench Moderation: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['state']['field'] = 'state';
$handler->display->display_options['fields']['state']['exclude'] = TRUE;
$handler->display->display_options['fields']['state']['machine_name'] = 0;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'nid';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<a href="/node/[nid]">[title]</a> 
<span class="status new [status] [state]">New [state]</span>
<span class="status revision [status] [state]">Revision [state]</span> 
<a class="node-edit-link" href="/node/[nid]/edit?destination=admin/workbench">(edit)</a>
<br/>
<span class="log-message">[log]</span>
[moderation_actions]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['relationship'] = 'nid';
$handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Revised by';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['relationship'] = 'nid';
$handler->display->display_options['fields']['changed']['label'] = 'Last updated';
$handler->display->display_options['fields']['changed']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['changed']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
$handler->display->display_options['fields']['changed']['custom_date_format'] = '1';
$handler->display->display_options['fields']['changed']['format_date_sql'] = 0;
$handler->display->display_options['path'] = 'admin/workbench/content/mine';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'My Content';
$handler->display->display_options['menu']['weight'] = '-5';
$handler->display->display_options['menu']['context'] = 0;
$translatables['incubator_workbench_author'] = array(
  t('Defaults'),
  t('My content'),
  t('view all'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('You haven\'t created or edited any content.'),
  t('Node'),
  t('revision user'),
  t('author'),
  t('Log message'),
  t('<br/>[log]'),
  t('Moderation history link'),
  t('Set moderation state'),
  t('Published'),
  t('State'),
  t('Title'),
  t('<a href="/node/[nid]">[title]</a> 
<span class="status new [status] [state]">New [state]</span>
<span class="status revision [status] [state]">Revision [state]</span> 
<a class="node-edit-link" href="/node/[nid]/edit?destination=admin/workbench">(edit)</a>
<br/>
<span class="log-message">[log]</span>
[moderation_actions]'),
  t('Type'),
  t('Author'),
  t('Revised by'),
  t('Last updated'),
  t('Needs review block'),
  t('For review'),
  t('more'),
  t('This list displays your content in the "Needs review" state. Currently there is no such content.'),
  t('Drafts block'),
  t('Drafts'),
  t('This list displays your content in the "Draft" state. Currently there is no such content.'),
  t('Content by me block'),
  t('You have not created any content.'),
  t('<span class="node-type">[type] : </span>
<a href="/node/[nid]">[title]</a> 
<span class="status new [status] [state]">New [state]</span>
<span class="status revision [status] [state]">Revision [state]</span> 
<a class="node-edit-link" href="/node/[nid]/edit?destination=admin/workbench">(edit)</a>
<br/>
<span class="log-message">[log]</span>
[moderation_actions]'),
  t('Content by me page'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
);

$views[] = $view; // ============================================================================================================================================


/*******************************************************************************
 *******************************************************************************
 * EDITOR VIEW
 *******************************************************************************
 ******************************************************************************/  


$view = new view();
$view->name = 'incubator_workbench_editor';
$view->description = 'Lists content by moderation state.';
$view->tag = 'Workbench Moderation';
$view->base_table = 'node_revision';
$view->human_name = 'Workbench Editor - Incubator';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Defaults */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->display->display_options['title'] = 'Editors\' workbench';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'view all';
$handler->display->display_options['link_display'] = 'content_by_me_page';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'moderate content from needs_review to published';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'nid' => 'nid',
  'log' => 'log',
  'workbench_moderation_history_link' => 'workbench_moderation_history_link',
  'moderation_actions' => 'moderation_actions',
  'status' => 'status',
  'state' => 'state',
  'title' => 'title',
  'type' => 'type',
  'name_1' => 'name_1',
  'name' => 'name',
  'changed' => 'changed',
);
$handler->display->display_options['style_options']['default'] = 'changed';
$handler->display->display_options['style_options']['info'] = array(
  'nid' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'log' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'workbench_moderation_history_link' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'moderation_actions' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'status' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'state' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'changed' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['content'] = 'You haven\'t created or edited any content.';
$handler->display->display_options['empty']['area']['format'] = '1';
/* Relationship: Workbench Moderation: Node */
$handler->display->display_options['relationships']['nid']['id'] = 'nid';
$handler->display->display_options['relationships']['nid']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['relationships']['nid']['field'] = 'nid';
$handler->display->display_options['relationships']['nid']['required'] = TRUE;
/* Relationship: Content revision: User */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Relationship: Content: Author */
$handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
$handler->display->display_options['relationships']['uid_1']['table'] = 'node';
$handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
$handler->display->display_options['relationships']['uid_1']['relationship'] = 'nid';
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['relationship'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content revision: Log message */
$handler->display->display_options['fields']['log']['id'] = 'log';
$handler->display->display_options['fields']['log']['table'] = 'node_revision';
$handler->display->display_options['fields']['log']['field'] = 'log';
$handler->display->display_options['fields']['log']['exclude'] = TRUE;
$handler->display->display_options['fields']['log']['alter']['text'] = '<br/>[log]';
$handler->display->display_options['fields']['log']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['log']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation history link */
$handler->display->display_options['fields']['workbench_moderation_history_link']['id'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['table'] = 'node';
$handler->display->display_options['fields']['workbench_moderation_history_link']['field'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['relationship'] = 'nid';
$handler->display->display_options['fields']['workbench_moderation_history_link']['exclude'] = TRUE;
$handler->display->display_options['fields']['workbench_moderation_history_link']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation links */
$handler->display->display_options['fields']['moderation_actions']['id'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['moderation_actions']['field'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['label'] = 'Set moderation state';
$handler->display->display_options['fields']['moderation_actions']['exclude'] = TRUE;
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['relationship'] = 'nid';
$handler->display->display_options['fields']['status']['exclude'] = TRUE;
$handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['status']['type'] = 'true-false';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Workbench Moderation: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['state']['field'] = 'state';
$handler->display->display_options['fields']['state']['exclude'] = TRUE;
$handler->display->display_options['fields']['state']['machine_name'] = 0;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'nid';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<a href="/node/[nid]">[title]</a> 
<span class="status new [status] [state]">New [state]</span>
<span class="status revision [status] [state]">Revision [state]</span> 
<a class="node-edit-link" href="/node/[nid]/edit?destination=admin/workbench">(edit)</a>
<br/>
<span class="log-message">[log]</span>
[moderation_actions]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['relationship'] = 'nid';
$handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
$handler->display->display_options['fields']['name_1']['table'] = 'users';
$handler->display->display_options['fields']['name_1']['field'] = 'name';
$handler->display->display_options['fields']['name_1']['relationship'] = 'uid_1';
$handler->display->display_options['fields']['name_1']['label'] = 'Author';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Revised by';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['relationship'] = 'nid';
$handler->display->display_options['fields']['changed']['label'] = 'Last updated';
$handler->display->display_options['fields']['changed']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['changed']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
$handler->display->display_options['fields']['changed']['custom_date_format'] = '1';
$handler->display->display_options['fields']['changed']['format_date_sql'] = 0;
/* Sort criterion: Content: Updated date */
$handler->display->display_options['sorts']['changed']['id'] = 'changed';
$handler->display->display_options['sorts']['changed']['table'] = 'node';
$handler->display->display_options['sorts']['changed']['field'] = 'changed';
$handler->display->display_options['sorts']['changed']['relationship'] = 'nid';
$handler->display->display_options['sorts']['changed']['order'] = 'DESC';
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['relationship'] = 'nid';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  7 => 0,
  8 => 0,
  3 => 0,
  6 => 0,
  4 => 0,
  5 => 0,
  9 => 0,
  10 => 0,
);
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'nid';
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  7 => 0,
  8 => 0,
  3 => 0,
  6 => 0,
  4 => 0,
  5 => 0,
  9 => 0,
  10 => 0,
);
/* Filter criterion: Workbench Moderation: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'draft' => 'draft',
  'needs_review' => 'needs_review',
  'published' => 'published',
);
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  7 => 0,
  8 => 0,
  3 => 0,
  6 => 0,
  4 => 0,
  5 => 0,
  9 => 0,
  10 => 0,
);
/* Filter criterion: Workbench Moderation: Current */
$handler->display->display_options['filters']['current']['id'] = 'current';
$handler->display->display_options['filters']['current']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['current']['field'] = 'current';
$handler->display->display_options['filters']['current']['value'] = '1';

/* Display: Needs review block */
$handler = $view->new_display('block', 'Needs review block', 'needs_review_block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'For review';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'This list displays content in the "Needs review" state that you can moderate. Currently there is no such content.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['relationship'] = 'nid';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'nid';
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
/* Filter criterion: Workbench Moderation: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'needs_review' => 'needs_review',
);
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  7 => 0,
  8 => 0,
  3 => 0,
  6 => 0,
  4 => 0,
  5 => 0,
  9 => 0,
  10 => 0,
);
/* Filter criterion: Workbench Moderation: Current */
$handler->display->display_options['filters']['current']['id'] = 'current';
$handler->display->display_options['filters']['current']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['current']['field'] = 'current';
$handler->display->display_options['filters']['current']['value'] = '1';

/* Display: Drafts block */
$handler = $view->new_display('block', 'Drafts block', 'recent_drafts_block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Drafts';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['link_url'] = '//admin/workbench/content/editor/state/?title=&type=All&state[]=draft';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'This list displays content in the "Draft" state that you can moderate. Currently there is no such content.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['relationship'] = 'nid';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'nid';
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
/* Filter criterion: Workbench Moderation: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['value'] = array(
  'draft' => 'draft',
);
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  7 => 0,
  8 => 0,
  3 => 0,
  6 => 0,
  4 => 0,
  5 => 0,
  9 => 0,
  10 => 0,
);
/* Filter criterion: Workbench Moderation: Current */
$handler->display->display_options['filters']['current']['id'] = 'current';
$handler->display->display_options['filters']['current']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['filters']['current']['field'] = 'current';
$handler->display->display_options['filters']['current']['value'] = '1';

/* Display: Content by me block */
$handler = $view->new_display('block', 'Content by me block', 'content_by_me_block');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['defaults']['use_more_always'] = FALSE;
$handler->display->display_options['use_more_always'] = TRUE;
$handler->display->display_options['defaults']['use_more_text'] = FALSE;
$handler->display->display_options['use_more_text'] = 'view all';
$handler->display->display_options['defaults']['link_display'] = FALSE;
$handler->display->display_options['link_display'] = 'content_by_me_page';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = '%1 has not created any content.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['empty']['area']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['relationship'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['relationship'] = 'nid';
$handler->display->display_options['fields']['type']['exclude'] = TRUE;
$handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
/* Field: Content revision: Log message */
$handler->display->display_options['fields']['log']['id'] = 'log';
$handler->display->display_options['fields']['log']['table'] = 'node_revision';
$handler->display->display_options['fields']['log']['field'] = 'log';
$handler->display->display_options['fields']['log']['exclude'] = TRUE;
$handler->display->display_options['fields']['log']['alter']['text'] = '<br/>[log]';
$handler->display->display_options['fields']['log']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['log']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation history link */
$handler->display->display_options['fields']['workbench_moderation_history_link']['id'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['table'] = 'node';
$handler->display->display_options['fields']['workbench_moderation_history_link']['field'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['relationship'] = 'nid';
$handler->display->display_options['fields']['workbench_moderation_history_link']['exclude'] = TRUE;
$handler->display->display_options['fields']['workbench_moderation_history_link']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation links */
$handler->display->display_options['fields']['moderation_actions']['id'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['moderation_actions']['field'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['label'] = 'Set moderation state';
$handler->display->display_options['fields']['moderation_actions']['exclude'] = TRUE;
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['relationship'] = 'nid';
$handler->display->display_options['fields']['status']['exclude'] = TRUE;
$handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['status']['type'] = 'true-false';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Workbench Moderation: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['state']['field'] = 'state';
$handler->display->display_options['fields']['state']['exclude'] = TRUE;
$handler->display->display_options['fields']['state']['machine_name'] = 0;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'nid';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<span class="node-type">[type] : </span>
<a href="/node/[nid]">[title]</a> 
<span class="status new [status] [state]">New [state]</span>
<span class="status revision [status] [state]">Revision [state]</span> 
<a class="node-edit-link" href="/node/[nid]/edit?destination=admin/workbench">(edit)</a>
<br/>
<span class="log-message">[log]</span>
[moderation_actions]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Revised by';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['relationship'] = 'nid';
$handler->display->display_options['fields']['changed']['label'] = 'Last updated';
$handler->display->display_options['fields']['changed']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['changed']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
$handler->display->display_options['fields']['changed']['custom_date_format'] = '1';
$handler->display->display_options['fields']['changed']['format_date_sql'] = 0;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: User: Uid */
$handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
$handler->display->display_options['arguments']['uid_1']['table'] = 'users';
$handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
$handler->display->display_options['arguments']['uid_1']['relationship'] = 'uid_1';
$handler->display->display_options['arguments']['uid_1']['default_action'] = 'default';
$handler->display->display_options['arguments']['uid_1']['title_enable'] = TRUE;
$handler->display->display_options['arguments']['uid_1']['title'] = 'Content by %1';
$handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';

/* Display: Content by me page */
$handler = $view->new_display('page', 'Content by me page', 'content_by_me_page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 25, 50, 100';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = '%1 has not created any content.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['empty']['area']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['relationship'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content revision: Log message */
$handler->display->display_options['fields']['log']['id'] = 'log';
$handler->display->display_options['fields']['log']['table'] = 'node_revision';
$handler->display->display_options['fields']['log']['field'] = 'log';
$handler->display->display_options['fields']['log']['exclude'] = TRUE;
$handler->display->display_options['fields']['log']['alter']['text'] = '<br/>[log]';
$handler->display->display_options['fields']['log']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['log']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation history link */
$handler->display->display_options['fields']['workbench_moderation_history_link']['id'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['table'] = 'node';
$handler->display->display_options['fields']['workbench_moderation_history_link']['field'] = 'workbench_moderation_history_link';
$handler->display->display_options['fields']['workbench_moderation_history_link']['relationship'] = 'nid';
$handler->display->display_options['fields']['workbench_moderation_history_link']['exclude'] = TRUE;
$handler->display->display_options['fields']['workbench_moderation_history_link']['hide_alter_empty'] = FALSE;
/* Field: Workbench Moderation: Moderation links */
$handler->display->display_options['fields']['moderation_actions']['id'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['moderation_actions']['field'] = 'moderation_actions';
$handler->display->display_options['fields']['moderation_actions']['label'] = 'Set moderation state';
$handler->display->display_options['fields']['moderation_actions']['exclude'] = TRUE;
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['relationship'] = 'nid';
$handler->display->display_options['fields']['status']['exclude'] = TRUE;
$handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['status']['type'] = 'true-false';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Workbench Moderation: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
$handler->display->display_options['fields']['state']['field'] = 'state';
$handler->display->display_options['fields']['state']['exclude'] = TRUE;
$handler->display->display_options['fields']['state']['machine_name'] = 0;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'nid';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<a href="/node/[nid]">[title]</a> 
<span class="status new [status] [state]">New [state]</span>
<span class="status revision [status] [state]">Revision [state]</span> 
<a class="node-edit-link" href="/node/[nid]/edit?destination=admin/workbench">(edit)</a>
<br/>
<span class="log-message">[log]</span>
[moderation_actions]';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['relationship'] = 'nid';
$handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Revised by';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['relationship'] = 'nid';
$handler->display->display_options['fields']['changed']['label'] = 'Last updated';
$handler->display->display_options['fields']['changed']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['changed']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
$handler->display->display_options['fields']['changed']['custom_date_format'] = '1';
$handler->display->display_options['fields']['changed']['format_date_sql'] = 0;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: User: Uid */
$handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
$handler->display->display_options['arguments']['uid_1']['table'] = 'users';
$handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
$handler->display->display_options['arguments']['uid_1']['relationship'] = 'uid_1';
$handler->display->display_options['arguments']['uid_1']['title_enable'] = TRUE;
$handler->display->display_options['arguments']['uid_1']['title'] = 'Content by %1';
$handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['path'] = 'admin/workbench/content/editor/%';

/* Display: Editors' workbench page */
$handler = $view->new_display('page', 'Editors\' workbench page', 'editors_workbench_page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 25, 50, 100';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There is no content marked as %1.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['empty']['area']['tokenize'] = TRUE;
$handler->display->display_options['path'] = 'admin/workbench/content/editor/all';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'All Content';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$translatables['incubator_workbench_editor'] = array(
  t('Defaults'),
  t('Editors\' workbench'),
  t('view all'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('You haven\'t created or edited any content.'),
  t('Node'),
  t('revision user'),
  t('author'),
  t('Log message'),
  t('<br/>[log]'),
  t('Moderation history link'),
  t('Set moderation state'),
  t('Published'),
  t('State'),
  t('Title'),
  t('<a href="/node/[nid]">[title]</a> 
<span class="status new [status] [state]">New [state]</span>
<span class="status revision [status] [state]">Revision [state]</span> 
<a class="node-edit-link" href="/node/[nid]/edit?destination=admin/workbench">(edit)</a>
<br/>
<span class="log-message">[log]</span>
[moderation_actions]'),
  t('Type'),
  t('Author'),
  t('Revised by'),
  t('Last updated'),
  t('Needs review block'),
  t('For review'),
  t('more'),
  t('This list displays content in the "Needs review" state that you can moderate. Currently there is no such content.'),
  t('Drafts block'),
  t('Drafts'),
  t('This list displays content in the "Draft" state that you can moderate. Currently there is no such content.'),
  t('Content by me block'),
  t('%1 has not created any content.'),
  t('<span class="node-type">[type] : </span>
<a href="/node/[nid]">[title]</a> 
<span class="status new [status] [state]">New [state]</span>
<span class="status revision [status] [state]">Revision [state]</span> 
<a class="node-edit-link" href="/node/[nid]/edit?destination=admin/workbench">(edit)</a>
<br/>
<span class="log-message">[log]</span>
[moderation_actions]'),
  t('All'),
  t('Content by %1'),
  t('Content by me page'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('Editors\' workbench page'),
  t('There is no content marked as %1.'),
);

$views[] = $view;
return $views;

}
