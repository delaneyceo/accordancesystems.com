(function ($) {
  Drupal.behaviors.accordancesystems = {
    attach: function(context, settings) {
      $('.accordancesystems-collapse', context).once('accordancesystems-collapse', function() {
        $(this).collapse({
          query: '.accordancesystems-trigger',
        });
      });
    }
  };

})(jQuery);
