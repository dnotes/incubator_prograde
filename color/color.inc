<?php

/**
 * @file
 *
 */

$info = array();

$info['fields'] = array(
  'bg' => t('Background'),                                          // $color_bg
  'base' => t('Main color'),                                      // $color_base
  'secondary' => t('Secondary color'),                       // $color_secondary
  'link' => t('Links'),                                           // $color_link
  'block' => t('Block borders'),                                // $color_border
  'text' => t('Text'),                                            // $color_text
  'text_highlight' => t('Text on Color'),               // $color_text_highlight
  'title' => t('Titles'),                                        // $color_title
);

$info['schemes']['default'] = array(
  'title' => t('Default'),
  'colors' => array(
    'bg' => '#fcfcfc',
    'base' => '#5a6f82',
    'secondary' => '#404e5b',
    'link' => '#476887',
    'block' => '#cdd4da',
    'text' => '#343434',
    'text_highlight' => '#fdfdfd',
    'title' => '#2f2f2f',
  ),
);

$info['css'] = array('css/colors.css');

$info['copy'] = array('logo.png');

$info['preview_css'] = 'css/preview.css';
$info['preview_js'] = 'color/preview.js';
$info['preview_html'] = 'color/preview.html';

// Gradients
$info['gradients'] = array();

// Color areas to fill (x, y, width, height)
$info['fill'] = array();

$info['slices'] = array();

$info['base_image'] = 'color/base.png';

$info['blend_target'] = '#ffffff';

$info['schemes']['sand'] = array(
  'title' => t('Sand'),
  'colors' => array(
    'bg' => '#fcfcfc',
    'base' => '#c0ab8f',
    'secondary' => '#967b56',
    'link' => '#219ea8',
    'block' => '#c0ab8f',
    'text' => '#343434',
    'text_highlight' => '#fcfcfc',
    'title' => '#226a70',
  )
);
$info['schemes']['akkabay'] = array(
  'title' => t("Bay of 'Akká"),
  'colors' => array(
    'bg' => '#6b6b6b',
    'base' => '#5ea9b5',
    'secondary' => '#f9f9d7',
    'link' => '#11bad4',
    'block' => '#415558',
    'text' => '#000000',
    'text_highlight' => '#fdfdfd',
    'title' => '#f9f9d7',
  ),
);
$info['schemes']['midnight'] = array(
  'title' => t('Midnight'),
  'colors' => array(
    'bg' => '#000000',
    'base' => '#29233e',
    'secondary' => '#000000',
    'link' => '#78abf2',
    'block' => '#29233e',
    'text' => '#f6f7d9',
    'text_highlight' => '#f6f7d9',
    'title' => '#274b7c',
  ),
);


return $info;