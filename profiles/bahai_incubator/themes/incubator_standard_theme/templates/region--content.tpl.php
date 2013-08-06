<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <a id="main-content"></a>
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
    <?php if ($title_hidden): ?><div class="element-invisible"><?php endif; ?>
    <h1 class="title" id="page-title"><?php print $title; ?></h1>
    <?php if ($title_hidden): ?></div><?php endif; ?>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
    <?php print $content; ?>
    <?php if ($feed_icons): ?><div class="feed-icon clearfix"><?php print $feed_icons; ?></div><?php endif; ?>
    <?php if ($main_menu || $secondary_menu): ?>
      <nav class="mobile-navigation">
        <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'mobile-main-menu', 'class' => array('links', 'clearfix', 'main-menu')), 'heading' => array('text' => t('Main menu'),'level' => 'h2','class' => array('element-invisible')))); ?>
        <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'mobile-secondary-menu', 'class' => array('links', 'clearfix', 'secondary-menu')), 'heading' => array('text' => t('Secondary menu'),'level' => 'h2','class' => array('element-invisible')))); ?>
      </nav>
    <?php endif; ?>
  </div>
</div>
