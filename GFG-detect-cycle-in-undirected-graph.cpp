// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool detect(int src, vector<int> adj[], vector<bool>& visited) {
        visited[src] = true;
        queue<pair<int,int>> q;         // {node,parent}
        q.push({src,-1});
        while(!q.empty()) {
            int node = q.front().first, parent = q.front().second;
            q.pop();
            for(int& adjacentNode: adj[node]) {
                if(!visited[adjacentNode]) {
                    visited[adjacentNode] = true;
                    q.push({adjacentNode,node});
                }
                else if(parent != adjacentNode) {
                    return true;
                }
            }
        }
        return false;
    }
    public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        for(int node = 0; node < V; node++) {
            if(!visited[node]) {
                if(detect(node,adj,visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};