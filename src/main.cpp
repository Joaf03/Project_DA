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

        std::cout << std::endl;
        menu::Menu(); //Call menu

        std::cout << "Please choose the option you prefer by writing the number that corresponds to it and then pressing return: " << std::endl;
        std::cin >> filter;

        if (filter == 1) {

            int userInput;
            std::cout << "Do you want to determine the maximum amount of water that can reach each or a specific city?: " << std::endl;
            std::cout << "1. Each City" << std::endl;
            std::cout << "2. Specific CIty" << std::endl;
            std::cin >> userInput;
            if(userInput == 1) {
                auto res = waterNeeds::maxFlow(mainGraph);
                std::cout << "This is the maximum flow of water: " << std::endl;
                std::cout << "City Code" << " | " << "Maximum Flow" << '\n';
                for(auto &city: res) cout << city.first << " | " << city.second << '\n';

            } else {
                std::string city;
                std::cout << "Enter the city code you want to determine the maximum amount of water that can reach it: ";
                std::cin >> city;
                auto result = waterNeeds::maxFlow(mainGraph, city);
                std::cout << "This is the maximum flow of water: " << std::endl;
                std::cout << "City Code" << " | " << "Maximum Flow" << '\n';
                for(auto &cityFlow: result) cout << cityFlow.first << " | " << cityFlow.second << '\n';
            }


            std::cout << "\nType 1 to return: ";
            std::cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                std::cout << "Invalid input. Type 1 to return: ";
                std::cin >> userInput;
            }
        }

        if (filter == 2) {

            int userInput;
            auto result = waterNeeds::citiesWithDeficit(mainGraph);
            std::cout << "These cities do not get enough water: " << std::endl;
            std::cout << "City Code" << " | " << "Deficit" << '\n';
            for(auto &city: result) cout << city.first << " | " << city.second << '\n';

            std::cout << "\nType 1 to return: ";
            std::cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                std::cout << "Invalid input. Type 1 to return: ";
                std::cin >> userInput;
            }
        }

        //Number of flights out from an Airport
        if (filter == 3) {

            // TO DO

            std::cout << "\nType 1 to return: ";
            int userInput;
            std::cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                std::cout << "Invalid input. Type 1 to return: ";
                std::cin >> userInput;
            }
        }

        //Number of different airlines with flights departing from an airport
        if (filter == 4) {

            // TO DO

            std::cout << "\nType 1 to return: ";
            int userInput;
            std::cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                std::cout << "Invalid input. Type 1 to return: ";
                std::cin >> userInput;
            }
        }

        //Number of flights per airline
        if (filter == 5) {

            // TO DO

            std::cout << "\nType 1 to return: ";
            int userInput;
            std::cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                std::cout << "Invalid input. Type 1 to return: ";
                std::cin >> userInput;
            }
        }

        //Number of flights per city
        if (filter == 6) {

            // TO DO

            std::cout << "\nType 1 to return: ";
            int userInput;
            std::cin >> userInput;

            // Validate user input if necessary
            while (userInput != 1) {
                std::cout << "Invalid input. Type 1 to return: ";
                std::cin >> userInput;
            }

        }

        //END THE PROGRAM
        if (filter == 0) {
            std::cout << "Thank you!";
            again = 0;
        }
    }

}