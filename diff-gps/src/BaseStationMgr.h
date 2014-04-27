#ifndef BaseStationMgr_H
#define BaseStationMgr_H

#include <stdint.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "BaseStation.h"

using namespace std;

class BaseStationMgr {

  private:
  	vector<BaseStation> baseStations;
  	int numLines;
  	void countLines();
  	double calDist(vector<double>,vector<double>);
  	BaseStation nearestStation(vector<double>);
  	void initializeStationList();
  public:
  	BaseStationMgr();
  	void getNearestRinex(ClientGpsData);
  	
};
#endif