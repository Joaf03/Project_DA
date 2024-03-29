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
    return reservoir;
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

int WaterReservoir::getMaxDelivery() const {
    return max_delivery;
}

void WaterReservoir::setReservoir(string n) {
    reservoir = n;
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
