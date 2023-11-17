

var collectionSize = sentinelMethaneRange.size();

// // Print the timestamp or date information for each image in the collection
// sentinelMethaneRange.toList(collectionSize).getInfo().forEach(function(image, index) {
//   var timeStart = ee.Image(image).get("system:time_start");
//   print("Image " + index, "system:time_start:", timeStart);
// });

sentinelMethaneRange = sentinelMethaneRange.map(function (image) {
  return image.copyProperties(image, ["system:time_start"]);
});

// // print ( typeof sentinelMethaneRange);

// // for (var key in sentinelMethaneRange) {

// //     print("Key:", key);

// // }

// FINDING THE TIME SERIES FROM THE IMPORTED DATA FOR METHANE
var timeSeriesMethane = sentinelMethaneRange.map(function (image) {
  var methaneConcentration = image
    .select("CH4_column_volume_mixing_ratio_dry_air")
    .reduceRegion({
      reducer: ee.Reducer.mean(),
      geometry: geometry,
      // scale: 1000,
      maxPixels: 1e13,
    })
    .get("CH4_column_volume_mixing_ratio_dry_air");
  return ee.Feature(null, {
    methaneConcentration: methaneConcentration,
    date: image.date().format(),
  });
});

// Iterate over the features in the FeatureCollection and print them to the console
timeSeriesMethane.getInfo().features.forEach(function (feature, index) {
  print("Feature " + index, feature);
});

// // EXPORTING METHANE DATA TO DRIVE
// Export.table.toDrive({
//   collection: timeSeriesMethane,
//   description: 'Sentinel_Methane_patna',
//   fileFormat: 'CSV'
// });

//Pollutants : CO , SO2 , NO2, Aerosol, Methane(CH4), Ozone(O3), Formaldehyde ( HCHO )  respectively
//City : Patna
// Duration : 2019 Jaunary to 2023 March
// Reducer : mean
// Type: Daily data
// Note : Data will be downloaded in user's google drive in the specified folder

// IMPORTING THE CO IMAGE DATA
// var sentinelCORange = SentinelCO.filterDate(
//   "2019-1-1",
//   "2023-04-1"
// ).filterBounds(geometry);
// sentinelCORange = sentinelCORange.map(function (image) {
//   return image.copyProperties(image, ["system:time_start"]);
// });

// //FINDING THE TIME SERIES FROM THE IMPORTED DATA FOR CO
// var timeSeriesCO = sentinelCORange.map(function (image) {
//   var CO_Density = image
//     .select("CO_column_number_density")
//     .reduceRegion({
//       reducer: ee.Reducer.mean(),
//       geometry: geometry,
//       // scale: 1000,
//       maxPixels: 1e13,
//     })
//     .get("CO_column_number_density");
//   return ee.Feature(null, {
//     CO_Density: CO_Density,
//     date: image.date().format(),
//   });
// });

// // Iterate over the features in the FeatureCollection and print them to the console
// timeSeriesCO.getInfo().features.forEach(function(feature, index) {
//   print("Feature " + index, feature);
// });
