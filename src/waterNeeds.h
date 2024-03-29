#ifndef UNTITLED2_WATERNEEDS_H
#define UNTITLED2_WATERNEEDS_H

#include <string>
#include <vector>
#include "Pipeline.h"
#include "Graph.h"


class waterNeeds {

public:
    static std::vector<std::pair<std::string, double>> citiesWithDeficit(Graph mainGraph);
};


#endif //UNTITLED2_WATERNEEDS_H
