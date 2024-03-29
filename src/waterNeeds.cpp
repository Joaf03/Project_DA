#include "waterNeeds.h"
#include "unordered_map"

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
