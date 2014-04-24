#include "GpsPostProcessor.h"

using namespace std;

GpsPostProcessor& GpsPostProcessor::getInstance() {
  static GpsPostProcessor instance;
  //myCsvHandler = CsvHandler();
  return instance;
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

  // while loop or something for gpp to handle incoming data with a call to
  // submitCsv() until it is shut down

  return 0;
}
