#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int& source, int& edges, int& nodes, unordered_map<int,vector<int>>& adj, vector<bool>& visited) {
        visited[source] = true;
        nodes++;
        for(int& neighbour: adj[source]) {
            edges++;
            if(visited[neighbour] == false) {
                this->dfs(neighbour,edges,nodes,adj,visited);
            }
        }
    }
    void bfs(int& source, int& edges, int& nodes, unordered_map<int,vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            nodes++;
            for(int& neighbour: adj[node]) {
                edges++;
                if(visited[neighbour] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(vector<int>& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        int answer = 0;
        for(int i=0; i<n; i++) {
            if(visited[i] == false) {
                int nodes = 0, edges = 0;
                // this->dfs(i,edges,nodes,adj,visited);
                this->bfs(i,edges,nodes,adj,visited);
                edges/= 2;
                if(edges == nodes*(nodes-1)/2) {
                    answer++;
                }
            }
        }
        return answer;
    }
};