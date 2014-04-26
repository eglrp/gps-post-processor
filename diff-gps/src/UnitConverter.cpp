#include "UnitConverter.h"

vector<double> UnitConverter::geoToCart(double lat, double lon, double alt) {
  gpstk::Triple geoTrip (lat, lon, alt);
  gpstk::Triple cartTrip;

  gpstk::Position::convertGeocentricToCartesian(geoTrip, cartTrip);

  vector<double> cartVec (3,0);
  cartVec[0] = cartTrip[0];
  cartVec[1] = cartTrip[1];
  cartVec[2] = cartTrip[2];

  return cartVec;
}

vector<double> UnitConverter::cartToGeo(double x, double y, double z) {
  gpstk::Triple cartTrip (x, y, z);
  gpstk::Triple geoTrip;

  gpstk::Position::convertCartesianToGeocentric(cartTrip, geoTrip);

  vector<double> geoVec (3,0);
  geoVec[0] = geoTrip[0];
  geoVec[1] = geoTrip[1];
  geoVec[2] = geoTrip[2];

  return geoVec;
}
