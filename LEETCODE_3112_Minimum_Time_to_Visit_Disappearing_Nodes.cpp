#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for(vector<int>& edge: edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        vector<int> distance(n, -1);
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        distance[0] = 0;
        
        // DIjkstra's algorithm
        while(pq.empty() == false) {
            int node = pq.top().second, weight = pq.top().first;
            pq.pop();
            if(visited[node] == true) {
                continue;
            }
            visited[node] = true;
            for(pair<int, int>& edge: graph[node]) {
                int neighbour = edge.first, new_weight = weight + edge.second;
                if(new_weight < disappear[neighbour] and (distance[neighbour] == -1 or new_weight < distance[neighbour])) {
                    pq.push({new_weight, neighbour});
                    distance[neighbour] = new_weight;
                }
            }
        }
        
        return distance;
    }
};