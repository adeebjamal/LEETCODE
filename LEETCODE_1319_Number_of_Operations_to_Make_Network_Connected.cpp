#include<bits/stdc++.h>
using namespace std;
class Solution {
    int number_of_components = 0, number_of_edges = 0;
    void bfs(int& source, vector<bool>& visited, unordered_map<int, vector<int>>& graph) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(q.empty() == false) {
            int node = q.front();
            q.pop();
            for(int& neighbour: graph[node]) {
                this->number_of_edges++;
                if(visited[neighbour] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    void dfs(int& node, vector<bool>& visited, unordered_map<int, vector<int>>& graph) {
        visited[node] = true;
        for(int& neighbour: graph[node]) {
            this->number_of_edges++;
            if(visited[neighbour] == false) {
                this->dfs(neighbour, visited, graph);
            }
        }
    }
    public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> graph;
        for(vector<int>& con: connections) {
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(con[0]);
        }
        vector<bool> visited(n, false);
        for(int node = 0; node < n; node++) {
            if(visited[node] == false) {
                this->number_of_components++;
                this->bfs(node, visited, graph);
                // this->dfs(node, visited, graph);
            }
        }
        this->number_of_edges /= 2;
        return this->number_of_edges < n - 1 ? -1 : this->number_of_components - 1;
    }
};