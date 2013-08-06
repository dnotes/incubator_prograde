(function ($) {

Drupal.behaviors.incubator = {
  attach: function (context, settings) {
    if (Drupal.settings.incubatorTaxonomyNoLinkTid) {
      $(".incubator-taxonomy-nolink-" + Drupal.settings.incubatorTaxonomyNoLinkTid + " a", context).each(function() {
        var $t = jQuery(this);
        $t.after($t.text());
        $t.remove();
      })
    }
  }
};

}(jQuery));