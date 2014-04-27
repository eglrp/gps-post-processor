#ifndef BaseStation_H
#define BaseStation_H

#include <stdint.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class BaseStation {

  private:
  	vector<double> trueEcefCoord;
  	string stationId;
  public:
  	BaseStation(vector<double>,string);
  	string getStationId();
  	vector<double> getTrueEcefCoord(); 
};
#endif