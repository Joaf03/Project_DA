#include "WaterReservoir.h"

WaterReservoir::WaterReservoir() = default;

WaterReservoir::WaterReservoir(string reservoir, string municipality, int reservoir_id, string code, int max_delivery){
    this->reservoir = reservoir;
    this->municipality = municipality;
    this->reservoir_id = reservoir_id;
    this->code = code;
    this->max_delivery = max_delivery;
}

string WaterReservoir::getReservoir() const{
    return this->reservoir;
}

string WaterReservoir::getMunicipality() const{
    return this->municipality;
}

int WaterReservoir::getReservoirId() const {
    return this->reservoir_id;
}

string WaterReservoir::getCode() const {
    return this->code;
}

int WaterReservoir::getMaxDelivery() const {
    return this->max_delivery;
}

void WaterReservoir::setReservoir(string n) {
    this->reservoir = n;
}

void WaterReservoir::setMunicipality(string m) {
    this->municipality = m;
}

void WaterReservoir::setReservoirId(int r){
    this->reservoir_id = r;
}

void WaterReservoir::setCode(string c) {
    this->code = c;
}

void WaterReservoir::setMaxDelivery(double d) {
    this->max_delivery = d;
}
