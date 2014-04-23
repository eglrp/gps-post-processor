#include "GpsPostProcessor.h"
#include "CsvHandler.h"

GpsPostProcessor& GpsPostProcessor::getInstance() {
  static GpsPostProcessor instance;
  return instance;
}

int main(int argc, char* argv[]) {
  GpsPostProcessor& gpp = GpsPostProcessor::getInstance();
  CsvHandler newCsvHandler("../client-data/loc_log__2014_62_1812.csv");
  // while loop or something for gpp to handle incoming data with a call to
  // submitCsv() until it is shut down

  return 0;
}
