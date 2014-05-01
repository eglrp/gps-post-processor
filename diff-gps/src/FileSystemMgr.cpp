#include "FileSystemMgr.h"
#include "UnitConverter.h"

using namespace std;

FileSystemMgr::FileSystemMgr(){}

string FileSystemMgr::getRinexUrl(string stationID, long long ut){ //string stationID, long ut
	// The Url is ftp://www.ngs.noaa.gov/cors/rinex/{4 CHAR YEAR}/{3 CHAR DAY OF YEAR}/{4 CHAR STATION ID}/
	string year = UnitConverter::getYear(ut);
	string day = UnitConverter::getDayOfYear(ut);
	string Url = "ftp://www.ngs.noaa.gov/cors/rinex/" + year +"/" + day +"/" + stationID + "/";
	return Url;
}


// test comment 
string FileSystemMgr::getAltRinexUrl(string stationID, long long ut) {
	// The Url is ftp://alt.ngs.noaa.gov/cors/rinex/{4 CHAR YEAR}/{3 CHAR DAY OF YEAR}/{4 CHAR STATION ID}/
	return "not done yet getAltRinexUrl\n";
}

string FileSystemMgr::getRinexDir(){
	return "not done yet getRinexDir\n";
}

string FileSystemMgr::getRinexFileName(string stationID, long long ut){
	// The RINEX filenames are {4 CHAR STATION ID}{3 CHAR DAY OF YEAR}0.{LAST TWO CHARS OF YEAR I.E. 14 FOR 2014}{either "n" for nav files or "o" for obs files}
	return "not done yet getRinexFileName\n";
}
string FileSystemMgr::getRinexPath(string stationID, long long ut){
	return "not done yet getRinexPath\n";
}

