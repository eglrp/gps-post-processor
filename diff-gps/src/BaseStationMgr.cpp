#include "BaseStationMgr.h"

using namespace std;

BaseStationMgr::BaseStationMgr() {
	vector<BaseStation> baseStations;
	fileName = "./config/cors.log";
	countLines();
	//initializeStationList();
}

void BaseStationMgr::countLines(){
	int number_of_lines = 0;
	string line;
	ifstream infile(this->fileName.c_str());
	while (getline(infile, line)) {
		//cout << line;
		++number_of_lines;
	}
	this->numStations = number_of_lines;
}

double BaseStationMgr::calDist(vector<double> stationEcef,vector<double> clientEcef) {}

BaseStation BaseStationMgr::nearestStation(vector<double> clientEcef) {}

void BaseStationMgr::initializeStationList() {
	baseStations.resize(numStations);
}

void BaseStationMgr::getNearestRinex(ClientGpsData myClientGpsData) {}