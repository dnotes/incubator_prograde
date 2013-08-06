/* $Id$ */

/**
 * Attaches the debugging behavior.
 */
(function($) {
  Drupal.behaviors.incubatorThemeSiteName = {
    attach: function (context) {
      $('body', context).once('header-resizing', function() {
        var compareHeight;
        var detector;
        var headerGroup;
        headerGroup = $('hgroup.site-name-slogan');
        detector = $('#region-branding .logo-img');
        compareHeight = detector.height();
        headerGroup.height(compareHeight);
        setPageFont();
        $(window).resize(function(){
          if (detector.height()!=compareHeight) {
            compareHeight = detector.height();
            headerGroup.height(compareHeight);
          }
          setPageFont();
        });
        function setPageFont() {
          if ($(window).width() < 320) {
            $('#page').css('font-size', '75%');
          }
          else {
            $('#page').css('font-size', '100%');
          }
        }
      })
    }
  };
  Drupal.behaviors.incubatorThemeMobileMenus = {
    attach: function (context) {
      function getMenu(elementclass, menuclass) {
        var menu = "";
        if (menu = $(menuclass).clone()) {
          if (menu.length !== 0) {
            $(elementclass).append(menu).addClass('has-content');
          }
        }
      }
      getMenu('#mobile-menu-user', '#block-system-user-menu ul.menu');
      getMenu('#mobile-menu-main', 'ul#mobile-main-menu');
      $('.incubator-mobile-menu').click(function() {
        $(this).parents('.incubator-mobile-menu-box').toggleClass('show-it').siblings('.incubator-mobile-menu-box').removeClass('show-it');
        return false;
      })
    }
  };
})(jQuery);

