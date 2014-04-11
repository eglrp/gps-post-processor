#include "ClientGpsData.h"

using namespace std;

vector<int> ClientGpsData::getTime() {
  return time;
}

void ClientGpsData::setTime(const vector<int> &time) {
  this->time = time;
}
