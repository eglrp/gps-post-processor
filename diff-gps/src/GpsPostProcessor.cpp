#include "GpsPostProcessor.h"

using namespace std;

GpsPostProcessor& GpsPostProcessor::getInstance() {
  static GpsPostProcessor instanceGPSPP;
  instanceGPSPP.unitConverter = UnitConverter();
  instanceGPSPP.myCsvHandler = CsvHandler();
  instanceGPSPP.fsMgr = FileSystemMgr();
  return instanceGPSPP;
}

void GpsPostProcessor::runPostProcessor(string filename) {
	ClientGpsData myClientData = myCsvHandler.getClientData(filename);
	//vector<long>  times = myClientData.getTheTime();
	//cout << times[0] << "\n" << times[1] << "\n"<< times[2] << "\n";
}



int main(int argc, char* argv[]) {

  GpsPostProcessor& gpp = GpsPostProcessor::getInstance();
  cout << "created instance of GpsPostProcessor\n";
  gpp.runPostProcessor("./client-data/loc_log__2014_62_1812.csv");
  cout << gpp.fsMgr.getRinexUrl();
  // unitconverter test code (best practice would be to have real unit tests with
  // known values)
  double lat = 1.0;
  double lon = 1.0;
  double alt = 1.0;
  double x = 1.0;
  double y = 1.0;
  double z = 1.0;

  vector<double> cartesian;
  cartesian = gpp.unitConverter.geoToCart(lat, lon, alt);
  printf("\n\nUnitConverter test geoToCart\n  in: %f, %f, %f\n", lat, lon, alt);
  printf("  out: %f, %f, %f\n", cartesian[0], cartesian[1], cartesian[2]);

  vector<double> geocentric;
  geocentric = gpp.unitConverter.cartToGeo(x, y, z);
  printf("UnitConverter test cartToGeo\n  in: %f, %f, %f\n", x, y, z);
  printf("  out: %f, %f, %f\n\n", geocentric[0], geocentric[1], geocentric[2]);

  // while loop or something for gpp to handle incoming data with a call to
  // submitCsv() until it is shut down

  return 0;
}
