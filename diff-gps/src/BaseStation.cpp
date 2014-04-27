#include "BaseStation.h"

using namespace std;

BaseStation::BaseStation(vector<double> pos,string ID) {
	this->trueEcefCoord = pos;
	this->stationId = ID;
}

vector<double> BaseStation::getTrueEcefCoord() {
	return this->trueEcefCoord;
}

string BaseStation::getStationId() {
	return this->stationId;
}