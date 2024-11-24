#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<pair<int, int>> mstEdges;
    public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> graph;
        // parent -> {neighbour, edgeWeight}
        for(int i = 0; i < points.size() - 1; i++) {
            for(int j = i + 1; j < points.size(); j++) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i].push_back({j, distance});
                graph[j].push_back({i, distance});
            }
        }
        int totalWeightMST = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {weight, node, parent}
        vector<bool> visited(points.size(), false);
        pq.push({0, 0, -1});
        while(pq.empty() == false) {
            int weight = pq.top()[0], node = pq.top()[1], parent = pq.top()[2];
            pq.pop();
            if(visited[node] == true) {
                continue;
            }
            if(parent != -1) {
                this->mstEdges.push_back({parent, node});
            }
            totalWeightMST += weight;
            visited[node] = true;
            for(pair<int, int>& edge: graph[node]) {
                int neighbour = edge.first, edgeWeight = edge.second;
                if(visited[neighbour] == false) {
                    pq.push({edgeWeight, neighbour, node});
                }
            }
        }
        return totalWeightMST;
    }
};