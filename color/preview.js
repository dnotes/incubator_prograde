// Handle the color changes and update the preview window.
(function ($) {
  Drupal.color = {
    logoChanged: false,
    callback: function(context, settings, form, farb, height, width) {
      // Background
      $('#preview', form).css('background-color', $('#palette input[name="palette[bg]"]', form).val());
      
      // Text
      $('#preview #preview-main', form).css('color', $('#palette input[name="palette[text]"]', form).val());
      
      // Links
      $('#preview #preview-main a:link', form).css('color', $('#palette input[name="palette[link]"]', form).val());
      
      // Base color
      
      // Secondary color
      
      // Text on Main color
      
      // Blocks and borders
      var block_bg = $('$palette input[name="skins[incubator_prograde_block_bg]"]').val();
      var border = $('#palette input[name="palette[block]"]', form).val();
      var color = border;
      if (block_bg === 'pagebg') {
        color = $('#palette input[name="palette[bg]"]', form).val();
      }
      else if (block_bg === 'white') {
        color = '#ffffff';
      }
      $('#preview .block', form).css('background-color', color).css('border-color', border);
      $('#preview .section-footer', form).css('background-color', color).css('border-color', border);
      $('#preview .teaser', form).css('background-color', color).css('border-color', border);
      
      
      // Titles
      $('#preview h2', form).css('color', $('#palette input[name="palette[title]"]', form).val());
      $('#preview h3', form).css('color', $('#palette input[name="palette[title]"]', form).val());
      
      
    }
  };
  Drupal.behaviors.exportColorscheme = {
    attach: function (context, settings) {
      $('#preview a.export-colors').click(function() {
        var colorscheme = '';
        var palette = $('#palette input[type=text]');
        palette.each(function() {
          colorscheme = colorscheme + "    '" + this.name.replace('palette[', '').replace(']', '') + "' => '" + $(this).val() + "',\n";
        });
        alert(colorscheme);
        return false;
      });
    }
  };
  Drupal.behaviors.sitenameSkinrColors = {
    attach: function (context, settings) {
      $('select[name="skins[incubator_prograde_block_bg]"]').change(function() {
//        $('#palette input[name="palette[headerglow]"]').change();
        var value = $(this).val();
        var color = $('#palette input[name="palette[block]"]').val();
        if (value === 'pagebg') {
          color = $('#palette input[name="palette[bg]"]').val();
        }
        else if (value === 'white') {
          color = '#ffffff';
        }
        $('#preview .block').css('background-color', color);
        $('#preview .section-footer').css('background-color', color);
        $('#preview .teaser').css('background-color', color);
      });
    }
  };
  
})(jQuery);
