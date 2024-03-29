#ifndef UNTITLED2_GRAPH_H
#define UNTITLED2_GRAPH_H

using namespace std;
#include <unordered_map>
#include "WaterReservoir.h"
#include "PumpingStation.h"
#include "DeliverySite.h"
#include "Pipeline.h"


class Graph {
private:
    unordered_map<string, WaterReservoir> waterReservoirs;
    unordered_map<string, PumpingStation> pumpingStations;
    unordered_map<string, DeliverySite> deliverySites;
    vector<Pipeline> pipelines;

public:
};


#endif
