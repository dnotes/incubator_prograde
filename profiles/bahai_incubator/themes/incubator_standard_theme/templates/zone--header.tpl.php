<?php 
/**
 * @file
 * Alpha's theme implementation to display a zone.
 */
?>
<div id="incubator-mobile-menu-bar">
  <div class="incubator-mobile-menu-box" id="mobile-menu-main">
    <a href="#" class="incubator-mobile-menu">main menu</a>
  </div>
  <div class="incubator-mobile-menu-box" id="mobile-menu-user">
    <a href="#" class="incubator-mobile-menu">user menu</a>
  </div>
</div>
<?php if ($wrapper): ?><div<?php print $attributes; ?>><?php endif; ?>
  <div id="header-banner-image" class="<?php print $header_banner_image_classes; ?>"></div>
  <div<?php print $content_attributes; ?>>
    <?php print $content; ?>
  </div>
<?php if ($wrapper): ?></div><?php endif; ?>