#include "DeliverySite.h"
using namespace std;

DeliverySite::DeliverySite() = default;

DeliverySite::DeliverySite(string city, int id, string code, double demand, double population){
    this->city = city;
    this->id = id;
    this->code = code;
    this->demand = demand;
    this->population = population;
}

string DeliverySite::getCity() const {
    return city;
}

int DeliverySite::getId() const {
    return id;
}

string DeliverySite::getCode() const {
    return code;
}

double DeliverySite::getDemand() const {
    return demand;
}

double DeliverySite::getPopulation() const {
    return population;
}

void DeliverySite::setCity(string city) {
    this->city = city;
}

void DeliverySite::setId(int i) {
    id = i;
}

void DeliverySite::setCode(string c) {
    code = c;
}

void DeliverySite::setDemand(double d) {
    demand = d;
}

void DeliverySite::setPopulation(int p) {
    population = p;
}
