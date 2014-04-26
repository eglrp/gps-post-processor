#ifndef UNIT_CONVERTER
#define UNIT_CONVERTER

#include <vector>
#include "Position.hpp"

using namespace std;

// facade class for some of GPSTk's coordinate and time conversion functionality
class UnitConverter {

public:
	UnitConverter() {};
	vector<double> geoToCart(double, double, double);
	vector<double> cartToGeo(double, double, double);

};

#endif
