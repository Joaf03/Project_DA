#include "WaterReservoir.h"

WaterReservoir::WaterReservoir() = default;

WaterReservoir::WaterReservoir(string name, string municipality, int reservoir_id, string code, double max_delivery){
    this->name = name;
    this->municipality = municipality;
    this->reservoir_id = reservoir_id;
    this->code = code;
    this->max_delivery = max_delivery;
}

string WaterReservoir::getName() const{
    return name;
}

string WaterReservoir::getMunicipality() const{
    return municipality;
}

int WaterReservoir::getReservoirId() const {
    return reservoir_id;
}

string WaterReservoir::getCode() const {
    return code;
}

double WaterReservoir::getMaxDelivery() const {
    return max_delivery;
}

void WaterReservoir::setName(string n) {
    name = n;
}

void WaterReservoir::setMunicipality(string m) {
    municipality = m;
}

void WaterReservoir::setReservoirId(int r){
    reservoir_id = r;
}

void WaterReservoir::setCode(string c) {
    code = c;
}

void WaterReservoir::setMaxDelivery(double d) {
    max_delivery = d;
}
