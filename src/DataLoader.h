#ifndef UNTITLED2_DATALOADER_H
#define UNTITLED2_DATALOADER_H

#include "WaterReservoir.h"
#include "PumpingStation.h"
#include "DeliverySite.h"
#include "Pipeline.h"

class DataLoader {
public:
    static vector<WaterReservoir> loadWaterReservoirs(const string &filename);
    static vector<PumpingStation> loadPumpingStations(string &filename);
    static vector<DeliverySite> loadDeliverySites(string &filename);
    static vector<Pipeline> loadPipelines(string &filename);

};

#endif
