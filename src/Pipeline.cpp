#include "Pipeline.h"
using namespace std;

Pipeline::Pipeline() = default;

Pipeline::Pipeline(string source, string target, double capacity, bool is_bidirectional){
    this->source = source;
    this->target = target;
    this->capacity = capacity;
    this->is_bidirectional = is_bidirectional;
    this->flow = 0;
}

string Pipeline::getSource() const {
    return source;
}

string Pipeline::getTarget() const {
    return target;
}

double Pipeline::getCapacity() const {
    return capacity;
}

double Pipeline::getFlow() const {
    return flow;
}

bool Pipeline::isBidirectional() const {
    return !is_bidirectional;
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

void Pipeline::setFlow(double f) {
    flow= f;
}