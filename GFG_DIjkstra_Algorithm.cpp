#include<bits/stdc++.h>
using namespace std;
class Solution {
	public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, S});
        vector<int> distance(V, 1e9);
        distance[S] = 0;
        while(pq.empty() == false) {
            int node = pq.top().second, dist = pq.top().first;
            pq.pop();
            for(vector<int>& edge: adj[node]) {
                int neighbour = edge[0], edgeweight = edge[1];
                if(distance[neighbour] > distance[node] + edgeweight) {
                    distance[neighbour] = distance[node] + edgeweight;
                    pq.push({distance[neighbour], neighbour});
                }
            }
        }
        for(int& num: distance) {
            if(num == 1e9) {
                num = -1;
            }
        }
        return distance;
    }
};