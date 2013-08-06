/* $Id$ */

(function ($) {

Drupal.behaviors.incubatorAdmin = {
  attach: function (context, settings) {
    $("#incubator-feature-settings fieldset input:checkbox", context).change(function() {
      if (this.checked) {
        $(this).parents('fieldset').removeClass('not-enabled').toggleClass('changed');
      }
      else {
        $(this).parents('fieldset').addClass('not-enabled').toggleClass('changed');
      }
    })
  }
};

}(jQuery));