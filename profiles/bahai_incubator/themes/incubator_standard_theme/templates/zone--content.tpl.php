<?php if ($wrapper): ?><div<?php print $attributes; ?>><?php endif; ?>  
  <div<?php print $content_attributes; ?>>    
    <?php if ($tabs && !empty($tabs['#primary'])): ?><div class="tabs clearfix"><?php print render($tabs); ?></div><?php endif; ?>
    <?php if ($breadcrumb): ?>
      <div id="breadcrumb" class="grid-<?php print $columns; ?>"><?php print $breadcrumb; ?></div>
    <?php endif; ?>
    <?php if ($messages): ?>
      <div id="messages" class="grid-<?php print $columns; ?>"><?php print $messages; ?></div>
    <?php endif; ?>
    <?php print $content; ?>
  </div>
<?php if ($wrapper): ?></div><?php endif; ?>