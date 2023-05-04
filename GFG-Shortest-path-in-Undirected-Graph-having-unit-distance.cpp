#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        unordered_map<int,vector<int>> adj;
        for(vector<int>& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> dist(N,1e9);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int& neighbour: adj[node]) {
                if(dist[node]+1 < dist[neighbour]) {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }
        for(int& it: dist) {
            if(it == 1e9) {
                it = -1;
            }
        }
        return dist;
    }
};