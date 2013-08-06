<?php
// $Id$

/**
 * @file
 *
 */

/**
 * Implements hook_skinr_skin_info().
 */
function incubator_standard_theme_skinr_skin_info() {
  $skins['incubator_standard_theme_typography'] = array(
    'title' => t('Font styles'),
    'group' => 'typography',
    'type' => 'select',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_standard_theme' => 1,
    ),
    'options' => array(
      '' => array('title' => t('Default'), 'class' => array('typ-default')),
      'bartik' => array(
        'title' => t('Bartik theme'),
        'class' => array('typ-bartik'),
      ),
      'newsy' => array(
        'title' => t('Newsy'), 
        'class' => array('typ-newsy'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=Playfair+Display+SC:700',
        )),
      ),
      'modern' => array(
        'title' => t('Modern'), 
        'class' => array('typ-modern'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=Economica|Julius+Sans+One|Gafata&subset=latin,latin-ext',
        )),
      ),
      'baskerville' => array(
        'title' => t('Baskerville'),
        'class' => array('typ-baskerville'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=Libre+Baskerville:400,i|Ubuntu:400,i,b,bi'
        ))
      ),
      'bree' => array(
        'title' => t('Bree'),
        'class' => array('typ-bree'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=Bree+Serif|Imprima&subset=latin,latin-ext'
        ))
      ),
      'montserrat' => array(
        'title' => t('Montserrat'),
        'class' => array('typ-montserrat'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=Montserrat:400|Pontano+Sans'
        ))
      ),
      'oswald' => array(
        'title' => t('Oswald'),
        'class' => array('typ-oswald'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=Oswald|Muli:400,300'
        ))
      ),
      'pt' => array(
        'title' => t('PT'),
        'class' => array('typ-pt'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=PT+Serif+Caption|PT+Sans'
        ))
      ),
      'vollkorn' => array(
        'title' => t('Vollkorn'),
        'class' => array('typ-vollkorn'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=Vollkorn|Raleway:300,600'
        ))
      ),
      'robotoworld' => array(
        'title' => t("Roboto Int'l"),
        'class' => array('typ-robotoworld'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=Roboto&subset=latin,latin-ext,greek,cyrillic,vietnamese'
        ))
      ),
      'josefin' => array(
        'title' => t('Josefin'),
        'class' => array('typ-josefin'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=Josefin+Slab:400,700|Maven+Pro'
        ))
      ),
      'paytone' => array(
        'title' => t('Paytone'),
        'class' => array('typ-paytone'),
        'attached' => array('css' => array(
          'http://fonts.googleapis.com/css?family=Paytone+One|Droid+Sans'
        ))
      ),
    ),
  );
  foreach ($skins['incubator_standard_theme_typography']['options'] as $name => $options) {
    if (!empty($name)) {
      $skins['incubator_standard_theme_typography']['options'][$name]['attached']['css'][] = "css/typography/$name.css";
    }
  }
  $skins['incubator_standard_theme_banner'] = array(
    'title' => t('Banner height'),
    'type' => 'select',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_standard_theme' => 1,
    ),
    'options' => array(
      '' => array('title' => t('Default'), 'class' => array('banner-default')),
      'short' => array('title' => t('Short'), 'class' => array('banner-short')),
      'tall' => array('title' => t('Tall'), 'class' => array('banner-tall')),
      'x-tall' => array('title' => t('Extra tall'), 'class' => array('banner-x-tall')),
    )
  );
  $skins['incubator_standard_theme_sitename'] = array(
    'title' => t('Site name style'),
    'type' => 'select',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_standard_theme' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-sitename.css'
      )
    ),
    'options' => array(
      '' => array('title' => t('< none >'), 'class' => array('sitename-nostyle')),
      'softglow' => array('title' => t('Soft glow'), 'class' => array('sitename-softglow')),
      'strongglow' => array('title' => t('Strong glow'), 'class' => array('sitename-strongglow')),
      'softshadow' => array('title' => t('Soft shadow'), 'class' => array('sitename-softshadow')),
      'strongshadow' => array('title' => t('Strong shadow'), 'class' => array('sitename-strongshadow')),
      'raised' => array('title' => t('Raised shadow'), 'class' => array('sitename-raised')),
      'softcolor' => array('title' => t('Soft color'), 'class' => array('sitename-softcolor')),
      'strongcolor' => array('title' => t('Strong color'), 'class' => array('sitename-strongcolor')),
      'raisedcolor' => array('title' => t('Raised color'), 'class' => array('sitename-raisedcolor')),
    )
  );
  $skins['incubator_standard_theme_blocks'] = array(
    'title' => t('Block styles'),
    'type' => 'select',
    'theme hooks' => array('html', 'block', 'region'),
    'default status' => 0,
    'status' => array(
      'incubator_standard_theme' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-blocks.css'
      )
    ),
    'options' => array(
      '' => array('title' => t('Default'), 'class' => array('blocks-default')),
      'noborders' => array('title' => t('No borders'), 'class' => array('blocks-noborders')),
      'headersonly' => array('title' => t('Headers only'), 'class' => array('blocks-headersonly')),
      'square' => array('title' => t('Square'), 'class' => array('blocks-square')),
      'roundedsmall' => array('title' => t('Rounded small'), 'class' => array('blocks-roundedsmall')),
      'roundedlarge' => array('title' => t('Rounded large'), 'class' => array('blocks-roundedlarge')),
      'diamondlt' => array('title' => t('Diamond left'), 'class' => array('blocks-diamondlt')),
      'diamondrt' => array('title' => t('Diamond right'), 'class' => array('blocks-diamondrt')),
    ),
  );
  $skins['incubator_standard_theme_menustyle'] = array(
    'title' => t('Main menu style'),
    'type' => 'checkboxes',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_standard_theme' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-menustyles.css'
      )
    ),
    'options' => array(
      'small' => array('title' => t('Small'), 'class' => array('menustyle-small')),
      'tiny' => array('title' => t('Very small'), 'class' => array('menustyle-tiny')),
      'linear' => array('title' => t('Linear'), 'class' => array('menustyle-linear')),
      'fullbar' => array('title' => t('Full bar'), 'class' => array('menustyle-fullbar')),
      'seethru' => array('title' => t('See-through'), 'class' => array('menustyle-seethru')),
      'transparent' => array('title' => t('Transparent'), 'class' => array('menustyle-transparent')),
      'noshadow' => array('title' => t('No shadow'), 'class' => array('menustyle-noshadow')),
      'square' => array('title' => t('Square'), 'class' => array('menustyle-square')),
      'bigroundrt' => array('title' => t('Rounded right corner'), 'class' => array('menustyle-bigroundrt')),
      'bigroundlt' => array('title' => t('Rounded left corner'), 'class' => array('menustyle-bigroundlt')),
    )
  );
  $skins['incubator_standard_theme_misc'] = array(
    'title' => t('Misc. options'),
    'type' => 'checkboxes',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_standard_theme' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-misc.css'
      )
    ),
    'options' => array(
      'fullwidthheader' => array('title' => t('Full-width header'), 'class' => array('misc-fullwidthheader')),
      'transparentheader' => array('title' => t('Transparent header'), 'class' => array('misc-transparentheader')),
      'padblocks' => array('title' => t('Pad blocks'), 'class' => array('misc-padblocks')),
      'extendedfooter' => array('title' => t('Extended footer'), 'class' => array('misc-extendedfooter')),
      'blacktriptych' => array('title' => t('Black triptych text'), 'class' => array('misc-blacktriptych')),
      'whitetriptych' => array('title' => t('White triptych text'), 'class' => array('misc-whitetriptych')),
      'showpostyear' => array('title' => t('Show year on post dates'), 'class' => array('misc-showpostyear')),
    )
  );
  return $skins;
}
