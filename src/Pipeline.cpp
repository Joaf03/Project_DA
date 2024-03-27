#include "Pipeline.h"
using namespace std;

Pipeline::Pipeline() = default;

Pipeline::Pipeline(std::string source, std::string target, double capacity, bool is_bidirectional){
    this->source = source
}

std::string Pipeline::getSource() const {
    return source;
}

std::string Pipeline::getTarget() const {
    return target;
}

double Pipeline::getCapacity() const {
    return capacity;
}

bool Pipeline::isBidirectional() const {
    return is_bidirectional;
}

void Pipeline::setSource(string s) {
    source = s;
}

void Pipeline::setTarget(string t) {
    target = t;
}

void Pipeline::setCapacity(double c) {
    capacity = c;
}

void Pipeline::setBidirectional(bool i) {
    is_bidirectional = i;
}
