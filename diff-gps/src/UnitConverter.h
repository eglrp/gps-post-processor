#ifndef UNIT_CONVERTER
#define UNIT_CONVERTER

#include <vector>
#include "Position.hpp"
#include "WGS84Ellipsoid.hpp"

using namespace std;

// facade class for some of GPSTk's coordinate and time conversion functionality
class UnitConverter {
private:

public:
	UnitConverter();
	static vector<long double> geoToCart(long double, long double, long double); // Geodetic WGS84 Ellipsoid (degrees/meters) to ECEF Cartesian (meters)
	static vector<long double> cartToGeo(long double, long double, long double); // ECEF Cartesian (meters) to Geodetic WGS84 Ellipsoid (degrees/meters)
	static string getYear(int unixTime);
	static string getDayOfYear(int unixTime);

};

#endif
