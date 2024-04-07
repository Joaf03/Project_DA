#ifndef UNTITLED2_GRAPH_H
#define UNTITLED2_GRAPH_H

using namespace std;
#include <unordered_map>
#include <set>
#include "WaterReservoir.h"
#include "PumpingStation.h"
#include "DeliverySite.h"
#include "Pipeline.h"


/**
 * @brief The Graph class represents a network graph consisting of water reservoirs, pumping stations, delivery sites, and pipelines.
 *
 * It stores information about water reservoirs, pumping stations, delivery sites, and pipelines, and provides methods to add and retrieve
 * these entities from the graph.
 *
 * Time Complexity:
 * - Adding water reservoirs: O(n)
 * - Adding pumping stations: O(n)
 * - Adding delivery sites: O(n)
 * - Adding pipelines: O(n)
 * - Getting water reservoirs: O(1)
 * - Getting pumping stations: O(1)
 * - Getting delivery sites: O(1)
 * - Getting pipelines: O(1)
 * - BFS: O(V+E)
 * - Edmonds-Karp algorithm: O(VE^2)
 * - Updating water reservoirs: O(n)
 * - Determining cities affected by removed reservoir: O(C*VE^2)
 * - Determining cities affected by ruptured pipelines: O(VE^3)
 */
class Graph {
private:
    unordered_map<string, WaterReservoir> waterReservoirs;    /**< Map storing water reservoirs by their code. */
    unordered_map<string, PumpingStation> pumpingStations;     /**< Map storing pumping stations by their code. */
    unordered_map<string, DeliverySite> deliverySites;         /**< Map storing delivery sites by their code. */
    vector<Pipeline> pipelines;                                 /**< Vector storing pipelines. */
    static vector<double> bfs(const WaterReservoir& s, const DeliverySite& t, Graph& mainGraph, vector<vector<string>>& allPaths);

public:
    /**
     * @brief Adds a vector of delivery sites to the graph.
     *
     * @param sites Vector of delivery sites to be added.
     *
     * Time Complexity: O(n), where n is the number of delivery sites to be added.
     */
    void addDeliverySites(const vector<DeliverySite>& sites) {
        for (const auto& site : sites) {
            deliverySites[site.getCode()] = site;
        }
    }

    /**
     * @brief Adds a vector of pumping stations to the graph.
     *
     * @param stations Vector of pumping stations to be added.
     *
     * Time Complexity: O(n), where n is the number of pumping stations to be added.
     */
    void addPumpingStations(const vector<PumpingStation>& stations) {
        for (const auto& station : stations) {
            pumpingStations[station.getCode()] = station;
        }
    }

    /**
     * @brief Adds a vector of water reservoirs to the graph.
     *
     * @param reservoirs Vector of water reservoirs to be added.
     *
     * Time Complexity: O(n), where n is the number of water reservoirs to be added.
     */
    void addWaterReservoirs(const vector<WaterReservoir>& reservoirs) {
        for (const auto& reservoir : reservoirs) {
            waterReservoirs[reservoir.getCode()] = reservoir;
        }
    }

    /**
     * @brief Adds a vector of pipelines to the graph.
     *
     * @param pipes Vector of pipelines to be added.
     *
     * Time Complexity: O(n), where n is the number of pipelines to be added.
     */
    void addPipelines(const vector<Pipeline>& pipes) {
        for (const auto& pipe : pipes) {
            Pipeline auxPipe = pipe;
            pipelines.push_back(pipe);
            if(pipe.isBidirectional()) {
                auxPipe.setSource(pipe.getTarget());
                auxPipe.setTarget(pipe.getSource());
                pipelines.push_back(auxPipe);
            }
        }
    }

    /**
     * @brief Retrieves all water reservoirs stored in the graph.
     *
     * @return Unordered map containing water reservoirs indexed by their code.
     *
     * Time Complexity: O(1)
     */
    unordered_map<string, WaterReservoir> getWaterReservoirs() const {
        return waterReservoirs;
    }

    /**
     * @brief Retrieves all pumping stations stored in the graph.
     *
     * @return Unordered map containing pumping stations indexed by their code.
     *
     * Time Complexity: O(1)
     */
    unordered_map<string, PumpingStation> getPumpingStations() const {
        return pumpingStations;
    }

    /**
     * @brief Retrieves all delivery sites stored in the graph.
     *
     * @return Unordered map containing delivery sites indexed by their code.
     *
     * Time Complexity: O(1)
     */
    unordered_map<string, DeliverySite> getDeliverySites() const {
        return deliverySites;
    }

    /**
     * @brief Retrieves all pipelines stored in the graph.
     *
     * @return Vector containing all pipelines.
     *
     * Time Complexity: O(1)
     */
    vector<Pipeline>& getPipelines() {
        return pipelines;
    }

    /**
     * @brief Runs the Edmonds-Karp algorithm to find the maximum flow from a water reservoir to a delivery site.
     *
     * @return Maximum flow from the water reservoir to the delivery site.
     *
     * Time Complexity: O(VE^2), where V is the number of vertices in the graph and E is the number of edges.
     */
    static double edmondsKarp(const DeliverySite& t, Graph& mainGraph);

    /**
     * @brief Updates the water reservoirs stored in the graph.
     *
     * @param reservoirs Map containing the water reservoirs to be updated.
     *
     * Time Complexity: O(n), where n is the number of water reservoirs to be updated.
     */
    void updateWaterReservoirs(const unordered_map<string, WaterReservoir>& reservoirs);

    /**
     * @brief Determines the cities affected by the removal of a water reservoir.
     *
     * @return Unordered map containing the city code and the amount of water it will not receive.
     *
     * Time Complexity: O(VE^2), where V is the number of vertices in the graph and E is the number of edges.
     */
    static unordered_map<string, double> affectedCitiesAfterReservoirRemoval(Graph& mainGraph, const string& removedReservoir);

    /**
     * @brief Determines the cities affected by a pump failure.
     *
     * @return Unordered map containing the pump code and a vector of pairs of affected cities and the amount of water they will not receive.
     *
     * Time Complexity: O(PsVE^2)), where Ps is the number of pumping stations, V is the number of vertices in the graph and E is the number of edges.
     */
    static unordered_map<string, vector<pair<string, double>>> pumpAffectedCities(Graph &mainGraph);

    /**
     * @brief Determines the cities affected by a pipeline failure.
     *
     * @return Unordered map containing a vector of pairs of affected cities and the amount of water they will not receive.
     *
     * Time Complexity: O(VE^3), where V is the number of vertices in the graph and E is the number of edges.
     */
    static unordered_map<string, vector<pair<string, double>>> pipeAffectedCities(Graph& mainGraph, vector<Pipeline> pipelines = {});
};



#endif
