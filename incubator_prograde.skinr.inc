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
  $skins['incubator_prograde_typography'] = array(
    'title' => t('Font styles'),
    'group' => 'typography',
    'type' => 'select',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_prograde' => 1,
    ),
    'options' => array(
      '' => array('title' => t('Default'), 'class' => array('typ-default')),
      'prograde' => array(
        'title' => t('Prograde design'),
        'class' => array('typ-prograde'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=Roboto+Slab:400,700|Noto+Serif:400,400italic,700&subset=latin,cyrillic'
        ))
      ),
//      'newsy' => array(
//        'title' => t('Newsy'), 
//        'class' => array('typ-newsy'),
//        'attached' => array('css' => array(
//          'http://fonts.googleapis.com/css?family=Playfair+Display+SC:700',
//        )),
//      ),
//      'modern' => array(
//        'title' => t('Modern'), 
//        'class' => array('typ-modern'),
//        'attached' => array('css' => array(
//          'http://fonts.googleapis.com/css?family=Economica|Julius+Sans+One|Gafata&subset=latin,latin-ext',
//        )),
//      ),
//      'baskerville' => array(
//        'title' => t('Baskerville'),
//        'class' => array('typ-baskerville'),
//        'attached' => array('css' => array(
//          'http://fonts.googleapis.com/css?family=Libre+Baskerville:400,i|Ubuntu:400,i,b,bi'
//        ))
//      ),
//      'bree' => array(
//        'title' => t('Bree'),
//        'class' => array('typ-bree'),
//        'attached' => array('css' => array(
//          'http://fonts.googleapis.com/css?family=Bree+Serif|Imprima&subset=latin,latin-ext'
//        ))
//      ),
//      'montserrat' => array(
//        'title' => t('Montserrat'),
//        'class' => array('typ-montserrat'),
//        'attached' => array('css' => array(
//          'http://fonts.googleapis.com/css?family=Montserrat:400|Pontano+Sans'
//        ))
//      ),
//      'oswald' => array(
//        'title' => t('Oswald'),
//        'class' => array('typ-oswald'),
//        'attached' => array('css' => array(
//          'http://fonts.googleapis.com/css?family=Oswald|Muli:400,300'
//        ))
//      ),
//      'pt' => array(
//        'title' => t('PT'),
//        'class' => array('typ-pt'),
//        'attached' => array('css' => array(
//          'http://fonts.googleapis.com/css?family=PT+Serif+Caption|PT+Sans'
//        ))
//      ),
//      'vollkorn' => array(
//        'title' => t('Vollkorn'),
//        'class' => array('typ-vollkorn'),
//        'attached' => array('css' => array(
//          'http://fonts.googleapis.com/css?family=Vollkorn|Raleway:300,600'
//        ))
//      ),
//      'robotoworld' => array(
//        'title' => t("Roboto Int'l"),
//        'class' => array('typ-robotoworld'),
//        'attached' => array('css' => array(
//          'http://fonts.googleapis.com/css?family=Roboto&subset=latin,latin-ext,greek,cyrillic,vietnamese'
//        ))
//      ),
//      'josefin' => array(
//        'title' => t('Josefin'),
//        'class' => array('typ-josefin'),
//        'attached' => array('css' => array(
//          'http://fonts.googleapis.com/css?family=Josefin+Slab:400,700|Maven+Pro'
//        ))
//      ),
//      'paytone' => array(
//        'title' => t('Paytone'),
//        'class' => array('typ-paytone'),
//        'attached' => array('css' => array(
//          'http://fonts.googleapis.com/css?family=Paytone+One|Droid+Sans'
//        ))
//      ),
    ),
  );
  foreach ($skins['incubator_prograde_typography']['options'] as $name => $options) {
    if (!empty($name)) {
      $skins['incubator_prograde_typography']['options'][$name]['attached']['css'][] = "css/typography/$name.css";
    }
  }
  
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
