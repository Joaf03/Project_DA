#include "Graph.h"
#include <queue>
#include <string>
#include <cfloat>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

double Graph::bfs(WaterReservoir s, DeliverySite t, Graph& mainGraph, vector<string>& path, set<vector<string>>& foundPaths) {
    path.clear();
    path.push_back(s.getCode());
    vector<string> visited;
    queue<pair<vector<string>, double>> q;
    q.push({path, DBL_MAX});

    while (!q.empty()) {
        vector<string> cur_path = q.front().first;
        string cur = cur_path.back();
        double flow = q.front().second;
        q.pop();

        for (const auto& pipeline : mainGraph.getPipelines()) {
            if (pipeline.getSource() != cur)
                continue;
            string next = pipeline.getTarget();
            double capacity = pipeline.getCapacity();
            if (find(visited.begin(), visited.end(), next) == visited.end() && capacity > 0) {
                visited.push_back(next);
                double new_flow = min(flow, capacity);
                vector<string> new_path = cur_path;
                new_path.push_back(next);
                if (next == t.getCode()) {
                    path = new_path;
                    if (foundPaths.find(new_path) != foundPaths.end()) {
                        continue;
                    }
                    foundPaths.insert(new_path);
                    return new_flow;
                }
                q.push({new_path, new_flow});
            }
        }
    }

    return 0;
}

double Graph::edmondsKarp(WaterReservoir s, DeliverySite t, Graph& mainGraph) {
    vector<string> path;
    set<vector<string>> foundPaths;
    double flow = 0, bfs_result;

    while ((bfs_result = bfs(s, t, mainGraph, path, foundPaths)) != 0) {
        flow += bfs_result;
        string cur = t.getCode();
        while (cur != s.getCode()) {
            for (auto& pipe : mainGraph.getPipelines()) {
                if (pipe.getSource() == path.back() && pipe.getTarget() == cur) {
                    pipe.setFlow(pipe.getFlow() + bfs_result);
                }
                if (pipe.getSource() == cur && pipe.getTarget() == path.back()) {
                    pipe.setFlow(pipe.getFlow() - bfs_result);
                }
            }
            cur = path.back();
            path.pop_back();
        }
    }

    return flow;
}