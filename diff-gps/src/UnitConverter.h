#ifndef UNIT_CONVERTER
#define UNIT_CONVERTER

#include <sstream>
#include <vector>
#include "Position.hpp"
#include "WGS84Ellipsoid.hpp"

using namespace std;

// facade class for some of GPSTk's coordinate and time conversion functionality
class UnitConverter {
private:

public:
	UnitConverter();
<<<<<<< HEAD
	vector<long double> geoToCart(long double, long double, long double); // Geodetic WGS84 Ellipsoid (degrees/meters) to ECEF Cartesian (meters)
	vector<long double> cartToGeo(long double, long double, long double); // ECEF Cartesian (meters) to Geodetic WGS84 Ellipsoid (degrees/meters)
	string getYear(int unixTime);
	string getDayOfYear(int unixTime);
=======
	static vector<long double> geoToCart(long double, long double, long double); // Geodetic WGS84 Ellipsoid (degrees/meters) to ECEF Cartesian (meters)
	static vector<long double> cartToGeo(long double, long double, long double); // ECEF Cartesian (meters) to Geodetic WGS84 Ellipsoid (degrees/meters)
	static string getYear(long long unixTime);
	static string getDayOfYear(long long unixTime);

>>>>>>> e02ab09ec165b95b57f0360edc6589ed21197a1c
};

#endif
