#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "CsvHandler.h"

using namespace std;



CsvHandler::CsvHandler(string filename)
{
	this->infile = filename;
	numLines();
	//cout << this->numLines << "\n";
	readCsv();
}
void CsvHandler::numLines()
{
	int number_of_lines = 0;
	string line;
	ifstream infile(this->infile.c_str());
	while (std::getline(infile, line)) ++number_of_lines;
	this->lines = number_of_lines;
}
void CsvHandler::readCsv(){
	
	vector<vector<double> > possitions;
	vector<vector<bool> > satellites;
	vector<long> times;
	possitions.resize(this->lines);
	satellites.resize(this->lines);
	times.resize(this->lines);

	for (int i = 0; i < this->lines; ++i) 
	{
		possitions[i].resize(3);
		satellites[i].resize(86);
		for (int j=0; j< 86; ++j) satellites[i][j] = false;
	}


    ifstream infile(this->infile.c_str());
    //ifstream infile("loc_log__2014_62_1812.csv");
    string line = "";
    int i = 0;
    while (getline(infile, line)){
        stringstream strstr(line);
        string word = "";
        int j = 0;
        while (getline(strstr,word, ',')) 
        {       	
        	if (j>3) { satellites[i][atoi(word.c_str())] = true; }
        	else if (j==0) { times[i] = atoi(word.c_str());}
        	else if (j==1) { possitions[i][0] = atof(word.c_str());}
        	else if (j==2) { possitions[i][1] = atof(word.c_str());}
        	else if (j==3) { possitions[i][2] = atof(word.c_str());}
        	//cout << word << '\n';
        	j++;
        }
       	i++;
    }
}