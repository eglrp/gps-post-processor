#include "GpsPostProcessor.h"

GpsPostProcessor& GpsPostProcessor::getInstance() {
  static GpsPostProcessor instance;
  return instance;
}

int main(int argc, char* argv[]) {
  GpsPostProcessor& gpp = GpsPostProcessor::getInstance();

  // while loop or something for gpp to handle incoming data with a call to
  // submitCsv() until it is shut down

  return 0;
}
