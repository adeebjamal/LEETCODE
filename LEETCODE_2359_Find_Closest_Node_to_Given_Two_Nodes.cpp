#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> dijkstra(int n, int source, unordered_map<int, vector<int>>& graph) {
        vector<int> distance(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distance[source] = 0;
        pq.push({0, source});
        while(pq.empty() == false) {
            int node = pq.top().second, dist = pq.top().first;
            pq.pop();
            for(int& neighbour: graph[node]) {
                if(distance[neighbour] > dist + 1) {
                    distance[neighbour] = dist + 1;
                    pq.push({dist + 1, neighbour});
                }
            }
        }
        return distance;
    }
    public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < edges.size(); i++) {
            if(edges[i] != -1) {
                graph[i].push_back(edges[i]);
            }
        }
        vector<int> distance1 = this->dijkstra(edges.size(), node1, graph);
        vector<int> distance2 = this->dijkstra(edges.size(), node2, graph);
        int answer = -1, min_dist = 1e9;
        for(int i = 0; i < edges.size(); i++) {
            if(min_dist > max(distance1[i], distance2[i])) {
                answer = i;
                min_dist = max(distance1[i], distance2[i]);
            }
        }
        return answer;
    }
};