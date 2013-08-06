// Handle the color changes and update the preview window.
(function ($) {
  Drupal.color = {
    logoChanged: false,
    callback: function(context, settings, form, farb, height, width) {
      // Text
      $('#preview #preview-content', form).css('color', $('#palette input[name="palette[text]"]', form).val());
      // Links
      $('#preview #preview-content a', form).css('color', $('#palette input[name="palette[links]"]', form).val());
      // Headers
      $('#preview h2', form).css('color', $('#palette input[name="palette[headers]"]', form).val());
      $('#preview h3', form).css('color', $('#palette input[name="palette[headers]"]', form).val());

      // Background Text
      $('#preview .preview-background', form).css('color', $('#palette input[name="palette[bgtext]"]', form).val());
      // Background Links
      $('#preview .preview-background a', form).css('color', $('#palette input[name="palette[bglinks]"]', form).val());

      // Header Background
      $('#preview #preview-header', form).css('backgroundColor', $('#palette input[name="palette[headerbg]"]', form).val());
      // Header Text
      $('#preview #preview-header', form).css('color', $('#palette input[name="palette[headertext]"]', form).val());
      // Menu Glow
      var glow_color = $('#palette input[name="palette[headerglow]"]', form).val();
      $('#preview #preview-main-menu-links li', form).css('box-shadow', '0px 0px 3px 2px ' + glow_color);
      $('#preview .site-name h1, #preview h6.site-slogan', form).css('text-shadow', 'none');
      $('#preview.sitename-softcolor .site-name h1, #preview.sitename-softcolor h6.site-slogan', form).css('text-shadow', '-1px 1px 3px ' + glow_color);
      $('#preview.sitename-strongcolor .site-name h1, #preview.sitename-strongcolor h6.site-slogan', form).css('text-shadow', '-2px 2px 1px ' + glow_color);
      $('#preview.sitename-raisedcolor .site-name h1, #preview.sitename-raisedcolor h6.site-slogan', form).css('text-shadow', '-3px 6px 5px ' + glow_color);

      // Menu item link bg
      $('#preview #preview-main-menu-links li', form).css('backgroundColor', $('#palette input[name="palette[menubg]"]', form).val());
      $('#preview #zone-menu', form).css('backgroundColor', $('#palette input[name="palette[menubg]"]', form).val());
      // Menu item link color
      $('#preview #preview-main-menu-links li a', form).css('color', $('#palette input[name="palette[menutext]"]', form).val());
      // Menu item active link bg
      $('#preview #preview-main-menu-links li.active', form).css('backgroundColor', $('#palette input[name="palette[menuactivebg]"]', form).val());
      // Menu item active link color
      $('#preview #preview-main-menu-links li.active a', form).css('color', $('#palette input[name="palette[menuactivetext]"]', form).val());

      // Block header
      $('#preview .block', form).css('backgroundColor', $('#palette input[name="palette[blockheaderbg]"]', form).val());
      $('#preview .block-inner', form).css('border-color', $('#palette input[name="palette[blockheaderbg]"]', form).val());
      // Block header text
      $('#preview h2.block-title', form).css('color', $('#palette input[name="palette[blockheadertext]"]', form).val());
      // Block background
      $('#preview .block-inner', form).css('backgroundColor', $('#palette input[name="palette[blockbg]"]', form).val());
      // Block text
      $('#preview .block-inner', form).css('color', $('#palette input[name="palette[blocktext]"]', form).val());
      // Block links
      $('#preview .block-inner a', form).css('color', $('#palette input[name="palette[blocklinks]"]', form).val());

      // Teasers
      $('#preview article.node-teaser', form)
      .css('backgroundColor', $('#palette input[name="palette[teaserbg]"]', form).val())
      .css('border-color', $('#palette input[name="palette[teaserborder]"]', form).val());

      // Submitted post info
      $('#preview article.node-teaser .teaser-submitted', form)
      .css('backgroundColor', $('#palette input[name="palette[submittedbg]"]', form).val())
      .css('color', $('#palette input[name="palette[submittedtext]"]', form).val());

      // Triptych background
      $('#preview #preview-triptych, #preview.misc-extendedfooter #preview-footer', form).css('backgroundColor', $('#palette input[name="palette[triptychbg]"]', form).val());
      // Triptych links
      $('#preview #preview-triptych a, #preview.misc-extendedfooter #preview-footer a', form).css('color', $('#palette input[name="palette[triptychlinks]"]', form).val());

      // CSS3 Gradients.
      var gradient_start = $('#palette input[name="palette[bgtop]"]', form).val();
      var gradient_end = $('#palette input[name="palette[bgmain]"]', form).val();

      $('#preview-background-gradient', form).attr('style', "background-color: " + gradient_start + "; background-image: -webkit-gradient(linear, 0% 0%, 0% 100%, from(" + gradient_start + "), to(" + gradient_end + ")); background-image: -moz-linear-gradient(-90deg, " + gradient_start + ", " + gradient_end + ");");
      $('#preview', form).css('background-color', gradient_end);

    }
  };
  Drupal.behaviors.exportColorscheme = {
    attach: function (context, settings) {
      $('#preview a.export-colors').click(function() {
        var colorscheme = '';
        var palette = $('#palette input[type=text]');
        palette.each(function() {
          colorscheme = colorscheme + "    '" + this.name.replace('palette[', '').replace(']', '') + "' => '" + $(this).val() + "',\n";
        })
        alert(colorscheme);
        return false;
      })
    }
  };
  Drupal.behaviors.sitenameSkinrColors = {
    attach: function (context, settings) {
      $('select[name="skins[incubator_standard_theme_sitename]"]').change(function() {
//        $('#palette input[name="palette[headerglow]"]').change();
        var glow_color = $('#palette input[name="palette[headerglow]"]').val();
        var value = $(this).val();
        if (value == 'softcolor') {
          $('#preview .site-name h1, #preview h6.site-slogan').css('text-shadow', '-1px 1px 3px ' + glow_color);
        }
        else if (value == 'strongcolor') {
          $('#preview .site-name h1, #preview h6.site-slogan').css('text-shadow', '-2px 2px 1px ' + glow_color);
        }
        else if (value == 'raisedcolor') {
          $('#preview .site-name h1, #preview h6.site-slogan').css('text-shadow', '-3px 6px 5px ' + glow_color);
        }
        else {
          $('#preview .site-name h1, #preview h6.site-slogan').css('text-shadow', 'none');
        }
      })
      $('input[name="skins[incubator_standard_theme_misc][extendedfooter]"]').change(function() {
        if ($(this).is(':checked')) {
          var bg_color = $('#palette input[name="palette[triptychbg]"]').val();
          $('#preview #preview-footer').css('background-color', bg_color);
          var tlink_color = $('#palette input[name="palette[triptychlinks]"]').val();
          $('#preview #preview-footer a').css('color', tlink_color);
        }
        else {
          var bglink_color = $('#palette input[name="palette[bglinks]"]').val();
          $('#preview #preview-footer a').css('color', bglink_color);
          $('#preview #preview-footer').css('background-color', 'transparent');
        }
      })
    }
  }
})(jQuery);
