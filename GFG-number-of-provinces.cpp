// https://practice.geeksforgeeks.org/problems/number-of-provinces/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    void dfs(int node, vector<bool>& visited, unordered_map<int,vector<int>>& adj) {
        visited[node] = true;
        for(int& neighbour: adj[node]) {
            if(visited[neighbour] == false) {
                dfs(neighbour,visited,adj);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        unordered_map<int,vector<int>> adjlist;
        for(int i=0; i<adj.size(); i++) {
            for(int j=0; j<adj[0].size(); j++) {
                if(adj[i][j] == 1 and i != j) {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        vector<bool> visited(V,false);
        int answer=0;
        for(int node=0; node<V; node++) {
            if(visited[node] == false) {
                answer++;
                dfs(node,visited,adjlist);
            }
        }
        return answer;
    }
};