#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> graph;
        int len = edges.size();
        for(int i = 0; i < len; i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        vector<double> probability(n, 0.0);
        priority_queue<pair<double, int>> pq;
        probability[start_node] = 1.0;
        pq.push({1.0, start_node});

        while(pq.empty() == false) {
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            for(pair<int, double>& edge: graph[node]) {
                int neighbour = edge.first;
                double edge_weight = edge.second;
                if(probability[neighbour] < prob * edge_weight) {
                    probability[neighbour] = prob * edge_weight;
                    pq.push({probability[neighbour], neighbour});
                }
            }
        }

        return probability[end_node];
    }
};