#include "UnitConverter.h"

UnitConverter::UnitConverter() {
  gpstk::WGS84Ellipsoid ellipsoid;

  A = ellipsoid.a();
  eccSq = ellipsoid.eccSquared();
}

vector<long double> UnitConverter::geoToCart(long double lat, long double lon, long double alt) {
  gpstk::Triple geoTrip (lat, lon, alt);
  gpstk::Triple cartTrip;

  gpstk::Position::convertGeodeticToCartesian(geoTrip, cartTrip, A, eccSq);

  vector<long double> cartVec (3,0);
  cartVec[0] = cartTrip[0];
  cartVec[1] = cartTrip[1];
  cartVec[2] = cartTrip[2];

  return cartVec;
}

vector<long double> UnitConverter::cartToGeo(long double x, long double y, long double z) {
  gpstk::Triple cartTrip (x, y, z);
  gpstk::Triple geoTrip;

  gpstk::Position::convertCartesianToGeodetic(cartTrip, geoTrip, A, eccSq);

  vector<long double> geoVec (3,0);
  geoVec[0] = geoTrip[0];
  geoVec[1] = geoTrip[1];
  geoVec[2] = geoTrip[2];

  return geoVec;
}
