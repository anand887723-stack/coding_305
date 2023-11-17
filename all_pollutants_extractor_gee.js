//Pollutants : CO , SO2 , NO2, Aerosol, Methane(CH4), Ozone(O3), Formaldehyde ( HCHO )  respectively
//City : Patna
// Duration : 2019 Jaunary to 2023 March
// Reducer : mean
// Type: Daily data
// Note : Data will be downloaded in user's google drive in the specified folder

// DEFINING THE BOUNDARY FOR THE PATNA USING GAUL LEVEL 2
var boundary = ee.FeatureCollection("FAO/GAUL_SIMPLIFIED_500m/2015/level2");
var geometry = boundary.filter(ee.Filter.eq("ADM2_NAME", "Patna"));

// IMPORTING THE CO IMAGE DATA
var sentinelCORange = SentinelCO.filterDate(
  "2019-1-1",
  "2023-04-1"
).filterBounds(geometry);
sentinelCORange = sentinelCORange.map(function (image) {
  return image.copyProperties(image, ["system:time_start"]);
});

//FINDING THE TIME SERIES FROM THE IMPORTED DATA FOR CO
var timeSeriesCO = sentinelCORange.map(function (image) {
  var CO_Density = image
    .select("CO_column_number_density")
    .reduceRegion({
      reducer: ee.Reducer.mean(),
      geometry: geometry,
      // scale: 1000,
      maxPixels: 1e13,
    })
    .get("CO_column_number_density");
  return ee.Feature(null, {
    CO_Density: CO_Density,
    date: image.date().format(),
  });
});

// EXPORTING  CO DATA TO DRIVE
Export.table.toDrive({
  collection: timeSeriesCO,
  description: "Sentinel_CO_patna",
  fileFormat: "CSV",
});

//⭐

// IMPORTING THE S02 IMAGE DATA

var sentinelSO2Range = SentinelSO2.filterDate(
  "2019-1-1",
  "2023-04-1"
).filterBounds(geometry);
sentinelSO2Range = sentinelSO2Range.map(function (image) {
  return image.copyProperties(image, ["system:time_start"]);
});

//FINDING THE TIME SERIES FROM THE IMPORTED DATA FOR SO2

var timeSeriesSO2 = sentinelSO2Range.map(function (image) {
  var SO2_Density = image
    .select("SO2_column_number_density")
    .reduceRegion({
      reducer: ee.Reducer.mean(),
      geometry: geometry,
      // scale: 1000,
      maxPixels: 1e13,
    })
    .get("SO2_column_number_density");
  return ee.Feature(null, {
    SO2_Density: SO2_Density,
    date: image.date().format(),
  });
});

//EXPORTING THE SO2 DATA TO DRIVE

Export.table.toDrive({
  collection: timeSeriesSO2,
  description: "Sentinel_SO2_patna",
  fileFormat: "CSV",
});

//⭐

// IMPORTING THE NO2 IMAGE DATA
var sentinelNO2Range = SentinelNO2.filterDate(
  "2019-1-1",
  "2023-04-1"
).filterBounds(geometry);
sentinelNO2Range = sentinelNO2Range.map(function (image) {
  return image.copyProperties(image, ["system:time_start"]);
});

//FINDING THE TIME SERIES FROM THE IMPORTED DATA FOR NO2

var timeSeriesNO2 = sentinelNO2Range.map(function (image) {
  var NO2_Density = image
    .select("NO2_column_number_density")
    .reduceRegion({
      reducer: ee.Reducer.mean(),
      geometry: geometry,
      // scale: 1000,
      maxPixels: 1e13,
    })
    .get("NO2_column_number_density");
  return ee.Feature(null, {
    NO2_Density: NO2_Density,
    date: image.date().format(),
  });
});

// EXPORTING THE NO2 DATA TO DRIVE
Export.table.toDrive({
  collection: timeSeriesNO2,
  description: "Sentinel_NO2_patna",
  fileFormat: "CSV",
});

//⭐

// IMPORTING THE AEROSOL IMAGE DATA

var sentinelAerosolRange = SentinelAerosol.filterDate(
  "2019-1-1",
  "2023-04-1"
).filterBounds(geometry);
sentinelAerosolRange = sentinelAerosolRange.map(function (image) {
  return image.copyProperties(image, ["system:time_start"]);
});

//FINDING THE TIME SERIES FROM THE IMPORTED DATA FOR AEROSOL

var timeSeriesAerosol = sentinelAerosolRange.map(function (image) {
  var Aerosol_Index = image
    .select("absorbing_aerosol_index")
    .reduceRegion({
      reducer: ee.Reducer.mean(),
      geometry: geometry,
      // scale: 1000,
      maxPixels: 1e13,
    })
    .get("absorbing_aerosol_index");
  return ee.Feature(null, {
    Aerosol_Density: Aerosol_Index,
    date: image.date().format(),
  });
});

//EXPORTING THE AEROSOL DATA TO DRIVE

Export.table.toDrive({
  collection: timeSeriesAerosol,
  description: "Sentinel_Aerosol_patna",
  fileFormat: "CSV",
});

//⭐

// IMPORTING THE METHANE IMAGE DATA

var sentinelmethaneRange = Sentinelmethane.filterDate(
  "2019-1-1",
  "2023-04-1"
).filterBounds(geometry);
sentinelmethaneRange = sentinelmethaneRange.map(function (image) {
  return image.copyProperties(image, ["system:time_start"]);
});

//FINDING THE TIME SERIES FROM THE IMPORTED DATA FOR methane

var timeSeriesmethane = sentinelmethaneRange.map(function (image) {
  var methane_Index = image
    .select("CH4_column_volume_mixing_ratio_dry_air") // exactify
    .reduceRegion({
      reducer: ee.Reducer.mean(),
      geometry: geometry,
      // scale: 1000,
      maxPixels: 1e13,
    })
    .get("CH4_column_volume_mixing_ratio_dry_air"); // exactify
  return ee.Feature(null, {
    CH4_Density: methane_Index,
    date: image.date().format(),
  });
});

//EXPORTING THE methane DATA TO DRIVE

Export.table.toDrive({
  collection: timeSeriesmethane,
  description: "Sentinel_methane_patna",
  fileFormat: "CSV",
});

//⭐

// IMPORTING THE ozone IMAGE DATA

var sentinelozoneRange = Sentinelozone.filterDate(
  "2019-1-1",
  "2023-04-1"
).filterBounds(geometry);
sentinelozoneRange = sentinelozoneRange.map(function (image) {
  return image.copyProperties(image, ["system:time_start"]);
});

//FINDING THE TIME SERIES FROM THE IMPORTED DATA FOR ozone

var timeSeriesozone = sentinelozoneRange.map(function (image) {
  var ozone_Index = image
    .select("O3_column_number_density") // exactify
    .reduceRegion({
      reducer: ee.Reducer.mean(),
      geometry: geometry,
      // scale: 1000,
      maxPixels: 1e13,
    })
    .get("O3_column_number_density"); // exactify
  return ee.Feature(null, {
    O3_Density: ozone_Index,
    date: image.date().format(),
  });
});

//EXPORTING THE ozone DATA TO DRIVE

Export.table.toDrive({
  collection: timeSeriesozone,
  description: "Sentinel_ozone_patna",
  fileFormat: "CSV",
});

//⭐

// IMPORTING THE formaldehyde IMAGE DATA

var sentinelformaldehydeRange = Sentinelformaldehyde.filterDate(
  "2019-1-1",
  "2023-04-1"
).filterBounds(geometry);
sentinelformaldehydeRange = sentinelformaldehydeRange.map(function (image) {
  return image.copyProperties(image, ["system:time_start"]);
});

//FINDING THE TIME SERIES FROM THE IMPORTED DATA FOR formaldehyde

var timeSeriesformaldehyde = sentinelformaldehydeRange.map(function (image) {
  var formaldehyde_Index = image
    .select("tropospheric_HCHO_column_number_density") // exactify
    .reduceRegion({
      reducer: ee.Reducer.mean(),
      geometry: geometry,
      // scale: 1000,
      maxPixels: 1e13,
    })
    .get("tropospheric_HCHO_column_number_density"); // exactify
  return ee.Feature(null, {
    HCHO_Density: formaldehyde_Index,
    date: image.date().format(),
  });
});

//EXPORTING THE formaldehyde DATA TO DRIVE

Export.table.toDrive({
  collection: timeSeriesformaldehyde,
  description: "Sentinel_formaldehyde_patna",
  fileFormat: "CSV",
});
