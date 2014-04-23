#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "ClientGpsData.h"
using namespace std;

class CsvHandler {
private:
	ClientGpsData readCsv();
	void numLines();
	string infile;
	int lines;

public:
	CsvHandler(string);
	ClientGpsData getClientData();
	string runOutput();
};

#endif