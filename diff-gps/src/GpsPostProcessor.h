#ifndef GPSPOSTPROCESSOR_H
#define GPSPOSTPROCESSOR_H

class GpsPostProcessor {

  private:
    GpsPostProcessor() {};
    GpsPostProcessor(GpsPostProcessor const&);
    GpsPostProcessor& operator=(GpsPostProcessor const&);

    // BaseStationMgr *    bsM;
    // CsvHandler *        csvHandler;
    // DownloadMgr *       dlMgr;
    // FileSystemMgr *     fsMgr;
    // RinexMgr *          rinexMgr;
    // UnitConverter *     unitConverter;

  public:
    static GpsPostProcessor& getInstance();

    // void submitCsv(ifstream csvData);
};

#endif
