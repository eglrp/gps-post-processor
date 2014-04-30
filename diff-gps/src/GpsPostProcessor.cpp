#include "GpsPostProcessor.h"

using namespace std;

GpsPostProcessor& GpsPostProcessor::getInstance() {
  static GpsPostProcessor instanceGPSPP;
  instanceGPSPP.unitConverter = UnitConverter();
  instanceGPSPP.myCsvHandler = CsvHandler();
  instanceGPSPP.fsMgr = FileSystemMgr();
  instanceGPSPP.bsMgr = BaseStationMgr();
  return instanceGPSPP;
}

void GpsPostProcessor::runPostProcessor(string filename) {
	ClientGpsData myClientData = myCsvHandler.getClientData(filename);
  vector<vector<long double> > clientGeo = myClientData.getInitialGeo();
  vector<vector<long double> > clientEcef = clientGeo;
  int size = clientGeo.size();
  for (int i=0;i<size;i++) {
    clientEcef[i] = unitConverter.geoToCart(clientGeo[i][0],clientGeo[i][1],clientGeo[i][2]);
  }
  myClientData.setInitialCart(clientEcef);
  bsMgr.getNearestRinex(myClientData);
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
  long double lat = 1.0;
  long double lon = 1.0;
  long double alt = 1.0;
  long double x = 1.0;
  long double y = 1.0;
  long double z = 1.0;

  vector<long double> cartesian;
  cartesian = gpp.unitConverter.geoToCart(lat, lon, alt);
  printf("\n\nUnitConverter test geoToCart\n  in: %Lf, %Lf, %Lf\n", lat, lon, alt);
  printf("  out: %Lf, %Lf, %Lf\n", cartesian[0], cartesian[1], cartesian[2]);

  vector<long double> geocentric;
  geocentric = gpp.unitConverter.cartToGeo(x, y, z);
  printf("UnitConverter test cartToGeo\n  in: %Lf, %Lf, %Lf\n", x, y, z);
  printf("  out: %Lf, %Lf, %Lf\n\n", geocentric[0], geocentric[1], geocentric[2]);



  // while loop or something for gpp to handle incoming data with a call to
  // submitCsv() until it is shut down

  return 0;
}
