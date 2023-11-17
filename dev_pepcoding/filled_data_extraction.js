var toCelsius = function (image) {
  return image.multiply(0.02).subtract(273.15);
};

for (var year = 2004; year <= 2020; year++) {
  for (var month = 1; month <= 12; month++) {
    var formattedMonth = month < 10 ? "0" + month : "" + month;
    var formattedYear = String(year);

    // Create the formatted date string
    var startdate = formattedYear + "-" + formattedMonth + "-01";
    var enddate = formattedYear + "-" + formattedMonth + "-28";

    var collection = ee
      .ImageCollection("MODIS/006/MOD11A2")
      .filter(ee.Filter.date(startdate, enddate))
      .select("LST_Day_1km");

    // Filter the collection based on the region of interest
    var filteredCollection = collection.filterBounds(roi);

    //Converting Temperature from Kelvin to Celsius

    // Apply the temperature conversion to the collection
    var convertedCollection = filteredCollection.map(toCelsius);

    // Get the median LST image in Celsius
    var medianImage = convertedCollection.median();

    // Define the export parameters

    var exportParams = {
      image: medianImage.toFloat(),
      description: startdate,
      scale: 1000, // Update with desired scale (e.g., 1000 for 1 km resolution)
      region: roi,
    };

    // Export the image as GeoTIFF
    Export.image.toDrive(exportParams);

    //  exportTable = exportTable.add(
    //    ee.Feature(null, {
    //      image: medianImage.select("LST_Day_1km").float(),
    //      description: startdate,
    //    })
    //  );

    // Print the export task status
    console.log("Exported this :" + startdate);
  }
}

// Export.table.toDrive({
//   collection: ee.FeatureCollection(exportTable),
//   description: "export_table",
//   fileFormat: "CSV",
// });
