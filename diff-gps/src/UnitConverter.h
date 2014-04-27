#ifndef UNIT_CONVERTER
#define UNIT_CONVERTER

#include <vector>
#include "Position.hpp"
#include "WGS84Ellipsoid.hpp"

using namespace std;

// facade class for some of GPSTk's coordinate and time conversion functionality
class UnitConverter {
private:
	// ellipsoid properties required for GPSTk's coordinate conversions
	double A;
	double eccSq;

public:
	UnitConverter();
	vector<double> geoToCart(double, double, double); // Geodetic WGS84 Ellipsoid (degrees/meters) to ECEF Cartesian (meters)
	vector<double> cartToGeo(double, double, double); // ECEF Cartesian (meters) to Geodetic WGS84 Ellipsoid (degrees/meters)
	//string getYear(int unixTime);
	//string getDayOfYear(int unixTime);

};

#endif
