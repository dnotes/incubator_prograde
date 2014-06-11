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
    'text_highlight' => '#fffffd',
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

return $info;