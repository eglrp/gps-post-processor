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

// string UnitConverter::getYear(CommonTime ct) {
//   return "YYYY";
// }

// string UnitConverter::getDayOfYear(CommonTime ct) {
//   return "DOY";
// }

string UnitConverter::getYear(int unixTime) {
  return "YYYY";
}

string UnitConverter::getDayOfYear(int unixTime) {
  return "DOY";
}
