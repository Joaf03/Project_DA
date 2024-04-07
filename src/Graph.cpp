#include "Graph.h"
#include "waterNeeds.h"
#include <queue>
#include <string>
#include <cfloat>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

vector<double> Graph::bfs(const WaterReservoir& s, const DeliverySite& t, Graph& mainGraph, vector<vector<string>>& allPaths) {
    vector<string> path;
    Graph graph_copy = mainGraph;
    path.push_back(s.getCode());
    vector<string> visited;
    priority_queue<pair<int, pair<vector<string>, double>>, vector<pair<int, pair<vector<string>, double>>>, greater<>> q;
    q.push({0, {path, DBL_MAX}});

    vector<double> min_flows;
    int min_path_length = INT_MAX;

    while (!q.empty()) {
        vector<string> cur_path = q.top().second.first;
        string cur = cur_path.back();
        double flow = q.top().second.second;
        int path_length = q.top().first;
        q.pop();

        if (cur == t.getCode()) {
            if (path_length < min_path_length) {
                min_path_length = path_length;
                allPaths.clear();
                min_flows.clear();
            }
            if (path_length == min_path_length) {
                allPaths.push_back(cur_path);
                min_flows.push_back(flow);
            }

            vector<string> path_copy = cur_path;
            while (cur != s.getCode()) {
                for (size_t i = 0; i < graph_copy.getPipelines().size(); ++i) {
                    if (graph_copy.getPipelines()[i].getSource() == path_copy.back() && graph_copy.getPipelines()[i].getTarget() == cur) {
                        graph_copy.getPipelines()[i].setCapacity(graph_copy.getPipelines()[i].getCapacity() - flow);
                    }
                    if (graph_copy.getPipelines()[i].getSource() == cur && graph_copy.getPipelines()[i].getTarget() == path_copy.back()) {
                        graph_copy.getPipelines()[i].setCapacity(graph_copy.getPipelines()[i].getCapacity() + flow);
                    }
                }
                cur = path_copy.back();
                path_copy.pop_back();
            }
            for(auto& reservoir: graph_copy.getWaterReservoirs()){
                if(reservoir.first == s.getCode()){
                    graph_copy.getWaterReservoirs()[reservoir.first].setMaxDelivery(reservoir.second.getMaxDelivery() - flow);
                }
            }
            continue;
        }

        for (const auto& pipeline : graph_copy.getPipelines()) {
            if (pipeline.getSource() != cur)
                continue;
            string next = pipeline.getTarget();
            double capastring = pipeline.getCapacity();
            if (find(visited.begin(), visited.end(), next) == visited.end() && capastring > 0) {
                WaterReservoir reservoir = graph_copy.getWaterReservoirs()[s.getCode()];
                vector<double> values = {flow, capastring, (double) reservoir.getMaxDelivery()};
                double new_flow = *min_element(values.begin(), values.end());

                vector<string> new_path = cur_path;
                new_path.push_back(next);
                if(next != t.getCode()) {
                    visited.push_back(next);
                }
                q.push({path_length + 1, {new_path, new_flow}});
            }
        }
    }

    mainGraph = graph_copy;
    return min_flows;
}

double Graph::edmondsKarp(const DeliverySite& t, Graph& mainGraph) {
    vector<vector<string>> allPaths;
    double total_flow = 0;
    vector<double> bfs_result;

    // Create a copy of the graph
    Graph graph_copy = mainGraph;

    for (const auto& s: mainGraph.getWaterReservoirs()) {
        // Run the bfs function on the graph's copy
        bfs_result = bfs(s.second, t, graph_copy, allPaths);

        // Add the flow of the paths to the total flow
        for (double flow : bfs_result) {
            total_flow += flow;
        }

        // Clear allPaths for the next iteration
        allPaths.clear();
    }

    mainGraph = graph_copy;
    return total_flow;
}

void Graph::updateWaterReservoirs(const unordered_map<string, WaterReservoir>& reservoirs) {
    for (const auto& reservoir : reservoirs) {
        waterReservoirs[reservoir.first] = reservoir.second;
    }
}

unordered_map<string, double> Graph::affectedCitiesAfterReservoirRemoval(Graph& mainGraph, const string& removedReservoir) {
    unordered_map<string, double> affectedCities;

    unordered_map<string, WaterReservoir> updatedReservoirs = mainGraph.getWaterReservoirs();
    updatedReservoirs.erase(removedReservoir);
    mainGraph.updateWaterReservoirs(updatedReservoirs);

    for (const auto& city : mainGraph.getDeliverySites()) {
        const string &cityCode = city.first;
        const DeliverySite &deliverySite = city.second;

        double newflow = waterNeeds::maxFlow(mainGraph, cityCode)[city.first];

        if (newflow < deliverySite.getDemand()) {
            double deficit = deliverySite.getDemand() - newflow;
            affectedCities[cityCode] = deficit;
        }
    }

    return affectedCities;
}

unordered_map<string, vector<pair<string, double>>> Graph::pumpAffectedCities(Graph &mainGraph) {
    unordered_map<string, vector<pair<string, double>>> affectedCities;    unordered_map<string, WaterReservoir> reservoirs = mainGraph.getWaterReservoirs();
    unordered_map<string, double> originalMaxFlows = waterNeeds::maxFlow(mainGraph, "");

    for (const auto& reservoir : reservoirs) {
        Graph copiedGraph = mainGraph;
        unordered_map<string, WaterReservoir> copyReservoirs = copiedGraph.getWaterReservoirs();
        copyReservoirs.erase(reservoir.first);

        unordered_map<string, double> copiedMaxFlows = waterNeeds::maxFlow(copiedGraph, "");

        for (const auto& originalMaxFlow : originalMaxFlows) {
            if (copiedMaxFlows[originalMaxFlow.first] < originalMaxFlow.second) {
                double deficit = originalMaxFlow.second - copiedMaxFlows[originalMaxFlow.first];
                affectedCities[reservoir.first].emplace_back(originalMaxFlow.first, deficit);
            }
        }
    }

    return affectedCities;
}

unordered_map<string, vector<pair<string, double>>> Graph::pipeAffectedCities(Graph& mainGraph, vector<Pipeline> pipelines){
    unordered_map<string, vector<pair<string, double>>> affectedCities;
    if(pipelines.empty()) pipelines = mainGraph.getPipelines();
    for(auto& pipe : pipelines){
        double cap = pipe.getCapacity();
        pipe.setCapacity(0);
        for(auto& city : mainGraph.getDeliverySites()){
            double flow = waterNeeds::maxFlow(mainGraph, city.first)[city.first];
            if(flow < city.second.getDemand()){
                double deficit = city.second.getDemand() - flow;
                affectedCities[pipe.getSource()+" - "+pipe.getTarget()].push_back({city.first, deficit});
            }
        }
        pipe.setCapacity(cap);
    }
    return affectedCities;
}