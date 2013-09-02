<?php
// $Id$

/**
 * @file
 *
 */

/**
 * Implements hook_skinr_skin_info().
 */
function incubator_prograde_skinr_skin_info() {
  $skins['incubator_prograde_block_bg'] = array(
    'title' => t('Block color'),
    'type' => 'select',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_prograde' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-block-bg.css'
      )
    ),
    'options' => array(
      '' => array('title' => t('Border, very light'), 'class' => array('block-bg-lighter')),
      'light' => array('title' => t('Border, light'), 'class' => array('block-bg-light')),
      'white' => array('title' => t('White'), 'class' => array('block-bg-white')),
      'pagebg' => array('title' => t('Page background'), 'class' => array('block-bg-pagebg')),
      'border' => array('title' => t('Border'), 'class' => array('block-bg-border')),
    )
  );
  return $skins;
}
