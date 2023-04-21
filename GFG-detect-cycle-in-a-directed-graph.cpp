// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool dfs(int node, vector<int> adj[], int vis[], int pathvis[]) {
        vis[node] = 1;
        pathvis[node] = 1;
        for(int& neighbour: adj[node]) {
            if(vis[neighbour] == 0) {
                if(dfs(neighbour,adj,vis,pathvis) == true) {
                    return true;
                }
            }
            else if(pathvis[neighbour] == 1) {
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
    public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0}, pathvis[V] = {0};
        for(int i=0; i<V; i++) {
            if(vis[i] == 0) {
                if(this->dfs(i,adj,vis,pathvis) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};