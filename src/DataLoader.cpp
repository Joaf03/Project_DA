using namespace std;
#include <fstream>
#include <sstream>
#include <iostream>
#include "DataLoader.h"


vector<WaterReservoir> DataLoader::loadWaterReservoirs(const string& filename) {
    vector<WaterReservoir> waterReservoirs;

    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return waterReservoirs;
    }

    string line;
    getline(file, line);
    while (getline(file, line)) {
        istringstream iss(line);
        string name, municipality, id_to_str, code, max_Delivery_to_str;
        int id, maxDelivery;

        getline(iss, name, ',');
        getline(iss, municipality, ',');
        getline(iss, id_to_str, ',');
        id = stoi(id_to_str);
        getline(iss, code, ',');
        getline(iss, max_Delivery_to_str);
        maxDelivery = stoi(max_Delivery_to_str);

        waterReservoirs.emplace_back(name, municipality, id, code, maxDelivery);
    }

    file.close();
    return waterReservoirs;
}

vector<PumpingStation> DataLoader::loadPumpingStations(string &filename) {
    vector<PumpingStation> pumpingStations;

    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return pumpingStations;
    }

    string line;
    getline(file, line);
    while (getline(file, line)) {
        istringstream iss(line);
        string id_to_str, code;
        int id;

        getline(iss, id_to_str, ',');
        id = stoi(id_to_str);
        getline(iss, code);

        pumpingStations.emplace_back(id, code);
    }

    file.close();
    return pumpingStations;
}

vector<DeliverySite> DataLoader::loadDeliverySites(string &filename) {
    vector<DeliverySite> deliverySites;

    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return deliverySites;
    }

    string line;
    getline(file, line);
    while (getline(file, line)) {
        istringstream iss(line);
        string city, id_to_str, code, demand_to_str, population_to_str;
        int id;
        double demand, population;
        getline(iss, city, ',');
        getline(iss, id_to_str, ',');
        id = stoi(id_to_str);
        getline(iss, code, ',');
        getline(iss, demand_to_str, ',');
        demand = stod(demand_to_str);
        getline(iss, population_to_str);
        population = stod(population_to_str);

        deliverySites.emplace_back(city, id, code, demand, population);
    }

    file.close();
    return deliverySites;
}

vector<Pipeline> DataLoader::loadPipelines(string &filename) {
    vector<Pipeline> pipelines;

    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return pipelines;
    }

    string line;
    getline(file, line);
    while (getline(file, line)) {
        istringstream iss(line);
        string source, target, capacity_to_str, direction_to_str;
        int capacity, direction;

        getline(iss, source, ',');
        getline(iss, target, ',');
        getline(iss, capacity_to_str, ',');
        capacity = stoi(capacity_to_str);
        getline(iss, direction_to_str, ',');
        direction = stoi(direction_to_str);

        pipelines.emplace_back(source, target, capacity, direction);
    }

    file.close();
    return pipelines;
}