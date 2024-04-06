#ifndef UNTITLED2_WATERNEEDS_H
#define UNTITLED2_WATERNEEDS_H

#include <string>
#include <vector>
#include "Pipeline.h"
#include "Graph.h"
#include "DeliverySite.h"
#include "WaterReservoir.h"


class waterNeeds {

public:
    static vector<pair<string, double>> citiesWithDeficit(Graph mainGraph);
    static unordered_map<string, double> maxFlow(Graph &mainGraph, const string& city = "");
    static void balanceLoad(Graph &mainGraph);
};


#endif //UNTITLED2_WATERNEEDS_H
