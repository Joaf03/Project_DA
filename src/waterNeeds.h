#ifndef UNTITLED2_WATERNEEDS_H
#define UNTITLED2_WATERNEEDS_H

#include <string>
#include <vector>
#include "Pipeline.h"
#include "Graph.h"
#include "DeliverySite.h"
#include "WaterReservoir.h"

/**
 * @brief The waterNeeds class contains methods to determine the cities with water deficit, the maximum flow that can be sent to each or a specific delivery site, and to balance the load of the pipelines.
 *
 * Time Complexity:
 * - Cities with deficit: O(P+C) where P is the number of pipelines and C is the number of cities.
 * - Maximum flow: O(R*C*V*E^2) where R is the number of water reservoirs, C is the number of cities, V is the number of vertices in the graph and E is the number of edges.
 * - Balance load: O(R*C*V*E^2) where R is the number of water reservoirs, C is the number of cities, V is the number of vertices in the graph and E is the number of edges.
 */
class waterNeeds {

public:
    /**
     * @brief Determines the cities with water deficit.
     *
     * @return Vector of pairs containing the city code and the deficit.
     *
     * Time Complexity: O(P+C) where P is the number of pipelines and C is the number of cities.
     */
    static vector<pair<string, double>> citiesWithDeficit(Graph mainGraph);

    /**
     * @brief Determines the maximum flow that can be sent to each or a specific delivery site.
     *
     * @return Unordered map containing the delivery site code and the maximum flow that can be sent to it.
     *
     * Time Complexity: O(R*C*V*E^2) where R is the number of water reservoirs, C is the number of cities, V is the number of vertices in the graph and E is the number of edges.
     */
    static unordered_map<string, double> maxFlow(Graph &mainGraph, const string& city = "");

    /**
     * @brief Balances the load of the pipelines.
     *
     * @return void
     *
     * Time Complexity: O(R*C*V*E^2) where R is the number of water reservoirs, C is the number of cities, V is the number of vertices in the graph and E is the number of edges.
     */
    static void balanceLoad(Graph &mainGraph);
};


#endif //UNTITLED2_WATERNEEDS_H
