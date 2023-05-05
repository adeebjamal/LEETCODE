// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9);
        dist[S] = 0;
        pq.push({0,S});
        while(!pq.empty()) {
            int dis = pq.top().first, node = pq.top().second;
            pq.pop();
            for(vector<int>& it: adj[node]) {
                int edgeWeight = it[1], adjNode = it[0];
                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
