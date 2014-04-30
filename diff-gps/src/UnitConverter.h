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
	long double A;
	long double eccSq;

public:
	UnitConverter();
	vector<long double> geoToCart(long double, long double, long double); // Geodetic WGS84 Ellipsoid (degrees/meters) to ECEF Cartesian (meters)
	vector<long double> cartToGeo(long double, long double, long double); // ECEF Cartesian (meters) to Geodetic WGS84 Ellipsoid (degrees/meters)
	string getYear(int unixTime);
	string getDayOfYear(int unixTime);

};

#endif
