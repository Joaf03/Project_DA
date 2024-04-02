#include "waterNeeds.h"
#include "unordered_map"
#include <string>
#include <vector>

using namespace std;

std::vector<std::pair<std::string, double>> waterNeeds::citiesWithDeficit(Graph mainGraph) {
    std::vector<std::pair<std::string, double>> citiesWithDeficit;
    std::unordered_map<std::string, double> cityGets;

    std::vector<Pipeline> pipelines = mainGraph.getPipelines();

    for (auto pipe: pipelines) {
        std::string target = pipe.getTarget();
        double capacity = pipe.getCapacity();
        cityGets[target] += capacity;
    }

    for (const auto& cityGet : cityGets) {
        if(cityGet.first[0] == 'C') {
            const std::string& city = cityGet.first;
            double get = cityGet.second;

            std::unordered_map<std::string, DeliverySite> deliverySites = mainGraph.getDeliverySites();

            DeliverySite deliverySite = deliverySites.at(city);

            if (get < deliverySite.getDemand()) {
                citiesWithDeficit.emplace_back(city, deliverySite.getDemand()-get);
            }
        }
    }

    return citiesWithDeficit;
}

unordered_map<string, double> waterNeeds::maxFlow(Graph mainGraph) {
    // this function should get the maxFlows using the Edmonds-Karp algorithm implemented in the Graph.cpp file
    unordered_map<string, double> maxFlows;
    unordered_map<string, DeliverySite> deliverySites = mainGraph.getDeliverySites();
    unordered_map<string, WaterReservoir> reservoirs = mainGraph.getWaterReservoirs();

    for (const auto& source : reservoirs) {
        for (const auto& sink : deliverySites) {
            double flow = Graph::edmondsKarp(source.second, sink.second, mainGraph);
            if (maxFlows.find(sink.first) == maxFlows.end() || flow > maxFlows[sink.first]) {
                maxFlows[sink.first] = flow;
            }
        }
    }
    return maxFlows;





}
