// FINDING THE TIME SERIES FROM THE IMPORTED DATA FOR METHANE
var timeSeriesMethane = sentinelMethaneRange.map(function(image) {
  var methaneConcentration = image..select("CH4_column_volume_mixing_ratio_dry_air")
    .reduceRegion({
      reducer: ee.Reducer.mean(),
        geometry: geometry,
      // scale: 1000,
      maxPixels: 1e13
    }).get('CH4_column_volume_mixing_ratio_dry_air');
  return ee.Feature(null, {Methane_Concentration: methaneConcentration, date: image.date().format()});
});



// Iterate over the features in the FeatureCollection and print them to the console
timeSeriesMethane.getInfo().features.forEach(function(feature, index) {
  print("Feature " + index, feature);
});
