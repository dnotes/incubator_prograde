<?php

/**
 * @file
 *
 */

$info = array();

$info['fields'] = array(
  'color_header_bg' => t('Header BG'),
  'color_bg' => t('Background'),
  'color_border' => t('Borders / Blocks'),
  'color_main_color' => t('Main color'),
  'color_main_color_darken' => t('Highlight color'),
  'color_text' => t('Text'),
  'color_link' => t('Links'),
);

$info['schemes']['default'] = array(
  'title' => t('Default'),
  'colors' => array(
    'color_header_bg' => '#fdfdfd',
    'color_bg' => '#fcfcfc',
    'color_border' => '#cdd4da',
    'color_main_color' => '#5a6f82',
    'color_main_color_darken' => '#404e5b',
    'color_text' => '#343434',
    'color_link' => '#476887',
    'color_title' => '#2f2f2f',
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

return $info;