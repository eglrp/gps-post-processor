#include "BaseStation.h"

using namespace std;

BaseStation::BaseStation() {
	
}
BaseStation::BaseStation(vector<double> pos,string ID) {
	this->trueEcefCoord = pos;
	this->stationId = ID;
}

vector<double> BaseStation::getTrueEcefCoord() {
	return this->trueEcefCoord;
}
void BaseStation::setTrueEcefCoord(vector<double> coord) {
	this->trueEcefCoord = coord;
}

string BaseStation::getStationId() {
	return this->stationId;
}
void BaseStation::setStationId(string ID) {
	this->stationId = ID;
}