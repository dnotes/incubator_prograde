/* $Id$ */

(function($) {
Drupal.fullcalendar.plugins.incubator_events = {
  options: function (fullcalendar, settings) {
    return {
      eventClick: function (calEvent, jsEvent, view) {
        if ($.inArray("bahaical", calEvent.className) === -1) {
          if (settings.sameWindow) {
            window.open(calEvent.url, '_self');
          }
          else {
            window.open(calEvent.url);
          }
        }
        return false;
      },
      events: function (start, end, callback) {
        // Fetch new items from Views if possible.
        if (settings.ajax && settings.fullcalendar_fields) {
          fullcalendar.dateChange(settings.fullcalendar_fields);
          if (fullcalendar.navigate) {
            if (!fullcalendar.refetch) {
              fullcalendar.fetchEvents();
            }
            fullcalendar.refetch = false;
          }
        }

        fullcalendar.parseEvents(callback);

        if (!fullcalendar.navigate) {
          // Add events from Google Calendar feeds.
          for (var entry in settings.gcal) {
            if (settings.gcal.hasOwnProperty(entry)) {
              fullcalendar.$calendar.find('.fullcalendar').fullCalendar('addEventSource',
                $.fullCalendar.gcalFeed(settings.gcal[entry][0], settings.gcal[entry][1])
              );
            }
          }
          // Show the Baha'i calendar
          if (typeof (Drupal.settings.incubatorBahaiCalendar) !== "undefined") {
            fullcalendar.$calendar.find('.fullcalendar').fullCalendar('addEventSource', Drupal.settings.incubatorBahaiCalendar);
          }
        }

        // Set navigate to true which means we've starting clicking on
        // next and previous buttons if we re-enter here again.
        fullcalendar.navigate = true;
      }
    };
  }
};

}(jQuery));