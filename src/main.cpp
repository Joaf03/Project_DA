#include <iostream>
#include "DataLoader.h"
#include "Graph.h"
#include "waterNeeds.h"
#include "menu.h"

using namespace std;

int main(){
    string filename = "../csv Files/Reservoir.csv";
    vector<WaterReservoir> waterReservoirs = DataLoader::loadWaterReservoirs(filename);

    // for (const WaterReservoir &waterReservoir: waterReservoirs) cout << waterReservoir.getReservoir() << '\n';

    filename = "../csv Files/Stations.csv";
    vector<PumpingStation> pumpingStations = DataLoader::loadPumpingStations(filename);

    // for (const PumpingStation &pumpingStation: pumpingStations) cout << pumpingStation.getId() << '\n';

    filename = "../csv Files/Cities.csv";
    vector<DeliverySite> deliverySites = DataLoader::loadDeliverySites(filename);

    // for (const DeliverySite &deliverySite: deliverySites) cout << deliverySite.getCity() << '\n';

    filename = "../csv Files/Pipes.csv";
    vector<Pipeline> pipelines = DataLoader::loadPipelines(filename);

    // for (const Pipeline &pipeline: pipelines) cout << pipeline.getSource() << '\n';

    // Create Main Graph
    Graph mainGraph;
    mainGraph.addDeliverySites(deliverySites);
    mainGraph.addPumpingStations(pumpingStations);
    mainGraph.addWaterReservoirs(waterReservoirs);
    mainGraph.addPipelines(pipelines);

    waterNeeds::citiesWithDeficit(mainGraph);
    // for(auto &city: result) cout << city.first << " " << city.second << '\n';

    waterNeeds::maxFlow(mainGraph);
    // for(auto &city: res) cout << city.first << " " << city.second << '\n';

    int filter;
    int again = 1;

    while (again == 1) {

        cout << endl;
        menu::Menu(); //Call menu

        cout << "Please choose the option you prefer by writing the number that corresponds to it and then pressing return: " << endl;
        cin >> filter;

        if (filter == 1) {

            int userInput;
            cout << "Do you want to determine the maximum amount of water that can reach each or a specific city?: " << endl;
            cout << "1. Each City" << endl;
            cout << "2. Specific CIty" << endl;
            cin >> userInput;
            if(userInput == 1) {
                auto res = waterNeeds::maxFlow(mainGraph);
                cout << "This is the maximum flow of water: " << endl;
                cout << "City Code" << " | " << "Maximum Flow" << '\n';
                for(auto &city: res) cout << city.first << " | " << city.second << '\n';

            } else {
                string city;
                cout << "Enter the city code you want to determine the maximum amount of water that can reach it: ";
                cin >> city;
                auto result = waterNeeds::maxFlow(mainGraph, city);
                cout << "This is the maximum flow of water: " << endl;
                cout << "City Code" << " | " << "Maximum Flow" << '\n';
                for(auto &cityFlow: result) cout << cityFlow.first << " | " << cityFlow.second << '\n';
            }


            cout << "\nType 1 to return: ";
            cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                cout << "Invalid input. Type 1 to return: ";
                cin >> userInput;
            }
        }

        if (filter == 2) {

            int userInput;
            auto result = waterNeeds::citiesWithDeficit(mainGraph);
            cout << "These cities do not get enough water: " << endl;
            cout << "City Code" << " | " << "Deficit" << '\n';
            for(auto &city: result) cout << city.first << " | " << city.second << '\n';

            cout << "\nType 1 to return: ";
            cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                cout << "Invalid input. Type 1 to return: ";
                cin >> userInput;
            }
        }

        if (filter == 3) {

            waterNeeds::balanceLoad(mainGraph);

            cout << "\nType 1 to return: ";
            int userInput;
            cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                cout << "Invalid input. Type 1 to return: ";
                cin >> userInput;
            }
        }

        if (filter == 4) {
            string r;
            cout << "Which water reservoir do you want to remove?" << endl;
            cin >> r;

            cout << "These cities will be affected by the removal of the water reservoir " << r << ": " << endl;
            Graph::affectedCitiesAfterReservoirRemoval(mainGraph, r);

            cout << "\nType 1 to return: ";
            int userInput;
            cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                cout << "Invalid input. Type 1 to return: ";
                cin >> userInput;
            }
        }

        if (filter == 5) {

            auto result = Graph::pumpAffectedCities(mainGraph);
            if(result.empty()) {
                cout << "No cities are affected by the removal of any pumping station." << endl;
            }
            for(auto &pump: result) {
                cout << "If the pumping station - " << pump.first << " - is temporarily taken out of service these cities - " << pump.second.size() << " - do not get enough water: " << endl;
                cout << "City | Deficit" << endl;
                for(auto &city: pump.second) {
                    cout << city.first << " | " << city.second << endl;
                }
            }

            cout << "\nType 1 to return: ";
            int userInput;
            cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                cout << "Invalid input. Type 1 to return: ";
                cin >> userInput;
            }
        }

        if (filter == 6) {
            int userInput;
            cout << "Do you want to examine each or a specific Pipeline?: " << endl;
            cout << "1. Each Pipeline" << endl;
            cout << "2. Specific Pipeline (you can insert multiple)" << endl;
            cin >> userInput;
            if(userInput == 1) {
                auto result = Graph::pipeAffectedCities(mainGraph);
                cout << "These cities do not get enough water: " << endl;
                cout << "Pipeline (Source -> Target): ";
                for (auto &pipe: result) {
                    cout << pipe.first << endl;
                    cout << "\tCity | Old Flow | New Flow" << endl;
                    for (auto &city: pipe.second) {
                        auto oldFlow = waterNeeds::maxFlow(mainGraph, city.first).at(city.first);
                        cout << "\t" << city.first << " | " << oldFlow << " | " << city.second << endl;
                    }
                    cout << '\n';
                }
            }
            else if(userInput == 2){
                string source, target;
                vector<Pipeline> pipelines;
                while(source != "0"){
                    cout << "Enter the code of the source of the pipeline you want to examine (Write 0 to advance):" << endl;
                    cin >> source;
                    if(source != "0"){
                        cout << "Now enter the code of the target of the pipeline:" << endl;
                        cin >> target;
                        for(auto &pipe: mainGraph.getPipelines()){
                            if(pipe.getSource() == source && pipe.getTarget() == target) pipelines.push_back(pipe);
                        }
                    }
                    else if(pipelines.empty()){
                        cout << "You must enter at least one Pipeline." << endl;
                        source = "";
                    }
                }
                auto result = Graph::pipeAffectedCities(mainGraph, pipelines);
                cout << "These cities do not get enough water: " << endl;
                cout << "Pipeline (Source -> Target): ";
                for (auto &pipe: result) {
                    cout << pipe.first << endl;
                    cout << "\tCity | Old Flow | New Flow" << endl;
                    for (auto &city: pipe.second) {
                        auto oldFlow = waterNeeds::maxFlow(mainGraph, city.first).at(city.first);
                        cout << "\t" << city.first << " | " << oldFlow << " | " << city.second << endl;
                    }
                    cout << '\n';
                }
            }
            cout << "\nType 1 to return: ";
            cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                cout << "Invalid input. Type 1 to return: ";
                cin >> userInput;
            }

        }

        //END THE PROGRAM
        if (filter == 0) {
            cout << "Thank you!";
            again = 0;
        }
    }

}