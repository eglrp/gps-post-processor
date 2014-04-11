#ifndef CLIENTGPSDATA_H
#define CLIENTGPSDATA_H

#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

class ClientGpsData {

  private:
		// TODO: fix these; we need consts for declaring length of member arrays,
		// and we have them in our initial design, but what do they need to be?
		//
		// "N" replaces "0..n" from the diagram
		// "M" replaces "0..m"
		// "AXES" replaces "3", I'm pretty sure this was because it's for
		//   3-dimensional coordinates
		static const int N = 1;
		static const int M = 1;
		static const int AXES = 3;

		vector<int> time;
    double initialCart[N][AXES];
    double correctedCart[N][AXES];
    double initialGeo[N][AXES];
    double correctedGeo[N][AXES];
    bool satellites[N][M];
    int8_t flags[N];
		string inUnits;
    string outUnits;
    string nearestStationID;
    double stationCoords[AXES];
    double stationDist;

  public:
    ClientGpsData();

		vector<int> getTime();
		void setTime(const vector<int>&);
};

#endif
