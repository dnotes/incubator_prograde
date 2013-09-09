<?php

/**
 * @file
 *
 */

$info = array();

$info['fields'] = array(
  'bg' => t('Background'),                                          // $color_bg
  'base' => t('Main color'),                                // $color_main_color
  'secondary' => t('Secondary color'),                 // $color_secondary_color
  'text' => t('Text'),                                            // $color_text
  'text_highlight' => t('Text highlights'),             // $color_text_highlight
  'link' => t('Links'),                                           // $color_link
  'block' => t('Borders / Blocks'),                             // $color_border
  'title' => t('Titles'),                                        // $color_title
);

$info['schemes']['default'] = array(
  'title' => t('Default'),
  'colors' => array(
    'bg' => '#fcfcfc',
    'base' => '#5a6f82',
    'secondary' => '#404e5b',
    'text' => '#343434',
    'link' => '#476887',
    'block' => '#cdd4da',
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

return $info;