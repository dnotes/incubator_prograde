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
  foreach ($skins['incubator_prograde_typography']['options'] as $name => $options) {
    if (!empty($name)) {
      $skins['incubator_prograde_typography']['options'][$name]['attached']['css'][] = "css/typography/$name.css";
    }
  }
  
  $skins['incubator_prograde_page_shadows'] = array(
    'title' => t('Page shadows'),
    'type' => 'select',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_prograde' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-page-shadows.css'
      )
    ),
    'options' => array(
      '' => array('title' => t('None'), 'class' => array('page-shadows-none')),
      'inset-header' => array('title' => t('Inset header'), 'class' => array('page-shadows-inset-header')),
      'raised-header' => array('title' => t('Raised header'), 'class' => array('page-shadows-raised-header')),
      'raised-page' => array('title' => t('Raised page'), 'class' => array('page-shadows-raised-page')),
    )
  );
  
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
  
  $skins['incubator_prograde_headers'] = array(
    'title' => t('Block headers'),
    'type' => 'checkboxes',
    'theme hooks' => array('html', 'block'),
    'default status' => 0,
    'status' => array(
      'incubator_prograde' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-headers.css',
      )
    ),
    'options' => array(
      'centered' => array('title' => t('Centered'), 'class' => array('headers-centered')),
      'colored' => array('title' => t('Colored background'), 'class' => array('headers-colored')),
      'top-aligned' => array('title' => t('Aligned with top'), 'class' => array('headers-top-aligned')),
      'link-text' => array('title' => t('Link color text'), 'class' => array('headers-link-text')),
      'link-bg' => array('title' => t('Link color background'), 'class' => array('headers-link-bg')),
      'secondary-text' => array('title' => t('Secondary color text'), 'class' => array('headers-secondary-text')),
      'secondary-bg' => array('title' => t('Secondary color background'), 'class' => array('headers-secondary-bg')),
      'banner' => array('title' => t('Banner'), 'class' => array('headers-banner')),
      'banner-right' => array('title' => t('Banner right'), 'class' => array('headers-banner-right', 'headers-banner-wide')),
      'banner-wide' => array('title' => t('Full-width banner'), 'class' => array('headers-banner-wide')),
    ),
  );
  
  $skins['incubator_prograde_main_block'] = array(
    'title' => t('Main content'),
    'type' => 'select',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_prograde' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-main-block.css'
      )
    ),
    'options' => array(
      '' => array('title' => t('Block styling'), 'class' => array('main-block-block')),
      'no-styling' => array('title' => t('No styling'), 'class' => array('main-block-no-styling')),
    ),
  );
  
  $skins['incubator_prograde_block_separators'] = array(
    'title' => t('Separators'),
    'type' => 'select',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_prograde' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-block-separators.css'
      )
    ),
    'options' => array(
      '' => array('title' => t('Same as border'), 'class' => array('block-separators-border')),
      'dotted' => array('title' => t('Dotted'), 'class' => array('block-separators-dotted')),
      'lightgray' => array('title' => t('Light gray'), 'class' => array('block-separators-lightgray')),
      'gray' => array('title' => t('Medium gray'), 'class' => array('block-separators-gray')),
      'darkgray' => array('title' => t('Dark gray'), 'class' => array('block-separators-darkgray')),
//      'lightmain' => array('title' => t('Light colored'), 'class' => array('block-separators-lightmain')),
//      'main' => array('title' => t('Medium colored'), 'class' => array('block-separators-main')),
//      'darkmain' => array('title' => t('Dark colored'), 'class' => array('block-separators-darkmain')),
//      'light-3d' => array('title' => t('Light 3d'), 'class' => array('block-separators-light-3d')),
//      'dark-3d' => array('title' => t('Dark 3d'), 'class' => array('block-separators-dark-3d')),
      'none' => array('title' => t('None'), 'class' => array('block-separators-none')),
    )
  );
  
  $skins['incubator_prograde_block_styles'] = array(
    'title' => t('Block styles'),
    'type' => 'checkboxes',
    'theme hooks' => array('html', 'block', 'region'),
    'default status' => 0,
    'status' => array(
      'incubator_prograde' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-block-styles.css'
      )
    ),
    'options' => array(
      'no-borders' => array('title' => t('No borders'), 'class' => array('block-styles-no-borders')),
      'no-background' => array('title' => t('No background'), 'class' => array('block-styles-no-background')),
      'rounded' => array('title' => t('Rounded'), 'class' => array('block-styles-rounded')),
      'heavy' => array('title' => t('Heavy'), 'class' => array('block-styles-heavy')),
      'shadowed' => array('title' => t('Shadowed'), 'class' => array('block-styles-shadowed')),
      'transparent' => array('title' => t('Transparent'), 'class' => array('block-styles-transparent')),
    )
  );
  
  $skins['incubator_prograde_main_menu_colors'] = array(
    'title' => t('Main menu colors'),
    'type' => 'select',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_prograde' => 1,
    ),
    'options' => array(
      '' => array('title'=> t('Base')),
      'linkcolor' => array('title'=> t('Link'), 'class' => array('main-menu-linkcolor')),
      'titlecolor' => array('title'=> t('Title'), 'class' => array('main-menu-titlecolor')),
      'secondarycolor' => array('title'=> t('Secondary'), 'class' => array('main-menu-secondarycolor')),
    ),
  );
  
  $skins['incubator_prograde_main_menu'] = array(
    'title' => t('Main menu styles'),
    'type' => 'checkboxes',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_prograde' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-main-menu.css'
      )
    ),
    'options' => array(
      'no-tabs' => array('title' => t('No tab coloring'), 'class' => array('main-menu-no-tabs')),
      'block' => array('title' => t('Block style'), 'class' => array('main-menu-block', '.main-menu-no-lineunder')),
      'overlay' => array('title' => t('Overlay header'), 'class' => array('main-menu-overlay', 'main-menu-no-lineunder')),
      'narrow-space' => array('title' => t('Narrow space'), 'class' => array('main-menu-narrow-space', 'main-menu-no-separators')),
      'wide-space' => array('title' => t('Wider space'), 'class' => array('main-menu-wide-space', 'main-menu-no-separators')),
      'narrow-items' => array('title' => t('Narrow items'), 'class' => array('main-menu-narrow-items')),
      'full-width' => array('title' => t('Full width'), 'class' => array('main-menu-full-width')),
      'no-separators' => array('title' => t('No separator bars'), 'class' => array('main-menu-no-separators')),
      'dot-separators' => array('title' => t('Dot separators'), 'class' => array('main-menu-dot-separators', 'main-menu-no-separators')),
      'no-lineunder' => array('title' => t('No line under'), 'class' => array('main-menu-no-lineunder')),
      'underline-items' => array('title' => t('Underline items'), 'class' => array('main-menu-underline-items', 'main-menu-no-lineunder', 'main-menu-no-separators')),
    )
  );
  
  $skins['incubator_prograde_main_menu_side'] = array(
    'title' => t('Menu position'),
    'type' => 'select',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_prograde' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-main-menu.css'
      )
    ),
    'options' => array(
      '' => array('title' => t('Normal'), 'class' => array('main-menu-side-normal')),
      'left' => array('title' => t('Left'), 'class' => array('main-menu-side-left')),
      'center' => array('title' => t('Center'), 'class' => array('main-menu-side-center')),
      'right' => array('title' => t('Right'), 'class' => array('main-menu-side-right')),
    )
  );
  
  $skins['incubator_prograde_user_menu_style'] = array(
    'title' => t('User menu'),
    'type' => 'select',
    'theme hooks' => array('html'),
    'default status' => 0,
    'status' => array(
      'incubator_prograde' => 1,
    ),
    'attached' => array(
      'css' => array(
        'css/skinr-user-menu.css'
      )
    ),
    'options' => array(
      '' => array('title' => t('Links')),
      'tabs' => array('title' => t('Tabs'), 'class' => array('user-menu-style-tabs')),
      'bar' => array('title' => t('Bar'), 'class' => array('user-menu-style-bar')),
    ),
  );
  
  
  return $skins;
}

function incubator_prograde_skinr_group_info() {
  return array(
    'incubator_prograde_general' => array(
      'title' => t('General'),
      'description' => t('Choose styles for page layout and typography.'),
    ),
    'incubator_prograde_blocks' => array(
      'title' => t('Blocks'),
      'description' => t('Choose styles for blocks of content.'),
    ),
    'incubator_prograde_menu' => array(
      'title' => t('Main menu'),
      'description' => t('Choose styles for the main menu.'),
    ),
    'incubator_prograde_color' => array(
      'title' => t('Secondary color'),
      'description' => t('Choose where the secondary color is used.'),
    ),
  );
}
