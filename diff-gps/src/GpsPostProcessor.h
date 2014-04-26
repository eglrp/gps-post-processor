#ifndef GPSPOSTPROCESSOR_H
#define GPSPOSTPROCESSOR_H

#include "CsvHandler.h"
#include "ClientGpsData.h"
#include "UnitConverter.h"
#include <vector>
#include <stdint.h>

class GpsPostProcessor {

  private:
    GpsPostProcessor() {};
    GpsPostProcessor(GpsPostProcessor const&);
    GpsPostProcessor& operator=(GpsPostProcessor const&);
    CsvHandler myCsvHandler;

    // BaseStationMgr *    bsM;
    // CsvHandler *        csvHandler;
    // DownloadMgr *       dlMgr;
    // FileSystemMgr *     fsMgr;
    // RinexMgr *          rinexMgr;

  public:
    UnitConverter unitConverter;

    static GpsPostProcessor& getInstance();
    void runPostProcessor(string);
    // void submitCsv(ifstream csvData);
};

#endif
