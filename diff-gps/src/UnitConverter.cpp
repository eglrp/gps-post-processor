#include "UnitConverter.h"

// Position, Triple, WGS84Ellipsoid
using namespace gpstk;
vector<long double> UnitConverter::geoToCart(long double lat, long double lon, long double alt) {
  Triple geoTrip (lat, lon, alt);
  Triple cartTrip;

  WGS84Ellipsoid ellipsoid;

  double A = ellipsoid.a();
  double eccSq = ellipsoid.eccSquared();

  Position::convertGeodeticToCartesian(geoTrip, cartTrip, A, eccSq);

  vector<long double> cartVec (3,0);
  cartVec[0] = cartTrip[0];
  cartVec[1] = cartTrip[1];
  cartVec[2] = cartTrip[2];

  return cartVec;
}

vector<long double> UnitConverter::cartToGeo(long double x, long double y, long double z) {
  Triple cartTrip (x, y, z);
  Triple geoTrip;

  WGS84Ellipsoid ellipsoid;

  double A = ellipsoid.a();
  double eccSq = ellipsoid.eccSquared();

  Position::convertCartesianToGeodetic(cartTrip, geoTrip, A, eccSq);

  vector<long double> geoVec (3,0);
  geoVec[0] = geoTrip[0];
  geoVec[1] = geoTrip[1];
  geoVec[2] = geoTrip[2];

  return geoVec;
}

// input: seconds in unix time
// output: the year as a string
string UnitConverter::getYear(long unixTime) {
  ostringstream oss;
  oss << unixTime / (60 * 60 * 24 * 365);
  return oss.str();
}

// input: seconds in unix time
// output: the day of the year as a string (1 is Jan 1, 365 is Dec 31)
string UnitConverter::getDayOfYear(long unixTime) {
  ostringstream oss;
  oss << (unixTime / (60 * 60 * 24)) % 365;
  return oss.str();
}
