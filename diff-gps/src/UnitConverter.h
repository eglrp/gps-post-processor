#ifndef UNIT_CONVERTER
#define UNIT_CONVERTER

#include <vector>
#include "Position.hpp"

using namespace std;

class UnitConverter {

public:
	UnitConverter();
	vector<double> geoToCart(double, double, double);
	vector<double> cartToGeo(double, double, double);

};

#endif
