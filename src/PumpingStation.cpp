#include "PumpingStation.h"
using namespace std;

PumpingStation::PumpingStation() = default;

PumpingStation::PumpingStation(int id, string code) {
    this->id = id;
    this->code = code;
}

int PumpingStation::getId() const {
    return id;
}

std::string PumpingStation::getCode() const {
    return code;
}

void PumpingStation::setId(int i) {
    id = i;
}

void PumpingStation::setCode(string c) {
    code = c;
}