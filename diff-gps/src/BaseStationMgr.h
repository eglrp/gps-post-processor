#ifndef BaseStationMgr_H
#define BaseStationMgr_H

#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "BaseStation.h"
#include "ClientGpsData.h"

using namespace std;

class BaseStationMgr {

  private:
  	vector<BaseStation> baseStations;
  	int numStations;
    string fileName;
  	void countLines();
  	double calDist(vector<double>,vector<double>);
  	BaseStation nearestStation(vector<double>);
  	void initializeStationList();
  public:
  	BaseStationMgr();
  	void getNearestRinex(ClientGpsData);
  	
};
#endif