#ifndef FILESYSTEMMGR_H
#define FILESYSTEMMGR_H

#include <stdint.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

class FileSystemMgr{
	public:
		FileSystemMgr();
		string getRinexUrl(); //string stationID, long ut
		string getAltRinexUrl(string stationID, long ut);
		string getRinexDir();
		string getRinexFileNames(string stationID, long ut);
		string getRinexPath(string stationID, long ut);

};

#endif