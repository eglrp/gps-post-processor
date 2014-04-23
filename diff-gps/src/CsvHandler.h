#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;

class CsvHandler {
private:
	void readCsv();
	void numLines();
	string infile;
	int lines;

public:
	CsvHandler(string);
	int runInput();
	string runOutput();
};

#endif