#include <iostream>
#include "DataLoader.h"
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
}