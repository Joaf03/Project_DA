#include "waterNeeds.h"
#include "unordered_map"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<string, double>> waterNeeds::citiesWithDeficit(Graph mainGraph) {
    vector<pair<string, double>> citiesWithDeficit;
    unordered_map<string, double> cityGets;

    vector<Pipeline> pipelines = mainGraph.getPipelines();

    for (auto pipe: pipelines) {
        string target = pipe.getTarget();
        double capacity = pipe.getCapacity();
        cityGets[target] += capacity;
    }

    for (const auto& cityGet : cityGets) {
        if(cityGet.first[0] == 'C') {
            const string& city = cityGet.first;
            double get = cityGet.second;

            unordered_map<string, DeliverySite> deliverySites = mainGraph.getDeliverySites();

            DeliverySite deliverySite = deliverySites.at(city);

            if (get < deliverySite.getDemand()) {
                citiesWithDeficit.emplace_back(city, deliverySite.getDemand()-get);
            }
        }
    }

    return citiesWithDeficit;
}

unordered_map<string, double> waterNeeds::maxFlow(Graph mainGraph, const string& city) {

    unordered_map<string, double> maxFlows;
    unordered_map<string, DeliverySite> deliverySites = mainGraph.getDeliverySites();
    unordered_map<string, WaterReservoir> reservoirs = mainGraph.getWaterReservoirs();

    if(city.empty()) {
        for (const auto& source : reservoirs) {
            for (const auto& sink : deliverySites) {
                double flow = Graph::edmondsKarp(source.second, sink.second, mainGraph);
                if (maxFlows.find(sink.first) == maxFlows.end() || flow > maxFlows[sink.first]) {
                    maxFlows[sink.first] = flow;
                }
            }
        }
    } else {
        for (const auto& source : reservoirs) {
            double flow = Graph::edmondsKarp(source.second, deliverySites.at(city), mainGraph);
            if (maxFlows.find(city) == maxFlows.end() || flow > maxFlows[city]) {
                maxFlows[city] = flow;
            }
        }
    }

    return maxFlows;
}

void waterNeeds::balanceLoad(Graph mainGraph) {
    vector<Pipeline> pipelines = mainGraph.getPipelines();
    vector<double> differences;
    double sumDiff = 0;
    double maxDiff = 0;
    int n = 0;
    for (auto pipe : pipelines){
        cout << "Flow: " << pipe.getFlow() << endl;
        double diff = pipe.getCapacity() - pipe.getFlow();
        differences.push_back(diff);
        if(diff > maxDiff) maxDiff = diff;
        sumDiff += diff;
    }

    double avgDiff = sumDiff / differences.size();
    double var = 0;
    for (auto val : differences) {
        var += (val - avgDiff) * (val - avgDiff);
    }
    var /= differences.size();

    cout << "Initial metrics:\n";
    cout << "\tAverage: " << avgDiff << "\n";
    cout << "\tVariance: " << var << "\n";
    cout << "\tMax difference: " << maxDiff << "\n";
    
    double totalCapacity = 0, totalFlow = 0;
    for(auto pipe: pipelines){
        totalCapacity += pipe.getCapacity();
        totalFlow += pipe.getFlow();
    }

    double avgFlow = totalFlow / pipelines.size();

    for(auto pipe: pipelines){
        double proportionalFlow = (pipe.getCapacity() / totalCapacity) * totalFlow;
        if(proportionalFlow > pipe.getFlow()){
            double additionalFlow = min(proportionalFlow - pipe.getFlow(), totalCapacity - totalFlow);
            cout << "Additional flow: " << additionalFlow << "\n\n";
            pipe.setFlow(pipe.getFlow() + additionalFlow);
            totalFlow += additionalFlow;
        }
    }

    differences.clear();
    sumDiff = 0;
    for (auto& pipe : pipelines){
        double diff = pipe.getCapacity() - pipe.getFlow();
        differences.push_back(diff);
        if(diff > maxDiff) pipe.setCapacity(pipe.getCapacity() - diff);
        sumDiff += diff;
    }

    avgDiff = sumDiff / differences.size();
    var = 0;
    for (auto& val : differences) {
        var += (val - avgDiff) * (val - avgDiff);
    }
    var /= differences.size();

    cout << "Metrics after balancing:\n";
    cout << "\tAverage: " << avgDiff << "\n";
    cout << "\tVariance: " << var << "\n";
    cout << "\tMax difference: " << maxDiff << "\n";
}