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
    void addDeliverySites(const vector<DeliverySite>& sites) {
        for (const auto& site : sites) {
            deliverySites[site.getCode()] = site;
        }
    }
    void addPumpingStations(const vector<PumpingStation>& stations) {
        for (const auto& station : stations) {
            pumpingStations[station.getCode()] = station;
        }
    }
    void addWaterReservoirs(const vector<WaterReservoir>& reservoirs) {
        for (const auto& reservoir : reservoirs) {
            waterReservoirs[reservoir.getCode()] = reservoir;
        }
    }
    void addPipelines(const vector<Pipeline>& pipes) {
        for (const auto& pipe : pipes) {
            pipelines.push_back(pipe);
        }
    }

    unordered_map<string, WaterReservoir> getWaterReservoirs() const {
        return waterReservoirs;
    }
    unordered_map<string, PumpingStation> getPumpingStations() const {
        return pumpingStations;
    }
    unordered_map<string, DeliverySite> getDeliverySites() const {
        return deliverySites;
    }
    vector<Pipeline> getPipelines() const {
        return pipelines;
    }
};


#endif
