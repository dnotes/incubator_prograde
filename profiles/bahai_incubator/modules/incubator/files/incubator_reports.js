/* $Id */

(function ($) {

google.load('visualization', '1.0', {'packages':['corechart']});
google.setOnLoadCallback(drawCharts);

function drawCharts() {
  var data, chart, options, type;
  for (x in Drupal.settings.incubator_reports) {
    data = google.visualization.arrayToDataTable($.makeArray(Drupal.settings.incubator_reports[x].data));
    type = Drupal.settings.incubator_reports[x].type;
    options = {
      'title':Drupal.settings.incubator_reports[x].caption,
      'width':Drupal.settings.incubator_reports[x].width,
      'height':Drupal.settings.incubator_reports[x].height,
      'chartArea':{left:10,top:20,height:"70%",width:"100%"},
      'vAxis':{'maxValue':20,'gridlines':{'count':5},'textPosition':'in'}
    };
    if (type == 'PieChart') {
      options.chartArea.height = "90%";
    }
    else if (type == 'BarChart') {
      options.chartArea.width = "70%";
      options.vAxis.textPosition = 'none';
    }
    else if (Drupal.settings.incubator_reports[x].type == 'AreaChart') {
      options.isStacked = true;
    }
    chart = new google.visualization[Drupal.settings.incubator_reports[x].type](document.getElementById(x));
    chart.draw(data, options);

  }
}

}(jQuery));
