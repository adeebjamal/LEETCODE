#include<bits/stdc++.h>
using namespace std;
class Graph {
    int n = 0;
    unordered_map<int,vector<pair<int,int>>> graph;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for(vector<int>& edge: edges) {
            this->graph[edge[0]].push_back({edge[1], edge[2]});     // from -> {to, time}
        }
    }
    
    void addEdge(vector<int> edge) {
        this->graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> distance(this->n, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        distance[node1] = 0;
        pq.push({0, node1});
        while(pq.empty() == false) {
            int node = pq.top().second, dist = pq.top().first;
            pq.pop();
            for(pair<int,int>& edge: graph[node]) {
                int neighbour = edge.first, edgeweight = edge.second;
                if(distance[neighbour] > dist + edgeweight) {
                    distance[neighbour] = dist + edgeweight;
                    pq.push({distance[neighbour], neighbour});
                }
            }
        }
        return (distance[node2] == 1e9) ? -1 : distance[node2];
    }
};