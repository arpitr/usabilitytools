/**
 * @fileOverview Add widget for usabilitytools
 * Get the API key and add usabilitytools tracker js
 */

(function($, Drupal, document) {
  Drupal.behaviors.usabilitytools = {
    attach: function (context, settings) {
      window['UsabilityTools Session Recording'] = {
        projectId: settings.usabilityTools.API
      };
      console.log(settings);
      var s = document.createElement('script');
      s.async = true;
      s.src = 'https://mobile.usabilitytools.com/recorder/tracker/tracker.js';
      document.head.appendChild(s);
      console.log(s);
    }
   }
})(jQuery, Drupal, document);
