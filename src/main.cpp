#include <iostream>
#include "DataLoader.h"
#include "Graph.h"
#include "waterNeeds.h"

using namespace std;

int main(){
    string filename = "../csv Files/Reservoir.csv";
    vector<WaterReservoir> waterReservoirs = DataLoader::loadWaterReservoirs(filename);

    for (const WaterReservoir &waterReservoir: waterReservoirs) cout << waterReservoir.getReservoir() << '\n';

    filename = "../csv Files/Stations.csv";
    vector<PumpingStation> pumpingStations = DataLoader::loadPumpingStations(filename);

    for (const PumpingStation &pumpingStation: pumpingStations) cout << pumpingStation.getId() << '\n';

    filename = "../csv Files/Cities.csv";
    vector<DeliverySite> deliverySites = DataLoader::loadDeliverySites(filename);

    for (const DeliverySite &deliverySite: deliverySites) cout << deliverySite.getCity() << '\n';

    filename = "../csv Files/Pipes.csv";
    vector<Pipeline> pipelines = DataLoader::loadPipelines(filename);

    for (const Pipeline &pipeline: pipelines) cout << pipeline.getSource() << '\n';

    // Create Main Graph
    Graph mainGraph;
    mainGraph.addDeliverySites(deliverySites);
    mainGraph.addPumpingStations(pumpingStations);
    mainGraph.addWaterReservoirs(waterReservoirs);
    mainGraph.addPipelines(pipelines);

    std::vector<std::pair<std::string, double>> result = waterNeeds::citiesWithDeficit(mainGraph);
    for(auto &city: result) cout << city.first << " " << city.second << '\n';

    auto res = waterNeeds::maxFlow(mainGraph);
    for(auto &city: res) cout << city.first << " " << city.second << '\n';

}