#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int,vector<int>> graph;
    bool dfs(int& source, int parent, unordered_map<int,bool>& visited) {
        visited[source] = true;
        for(int& neighbour: this->graph[source]) {
            if(visited[neighbour] == false) {
                if(this->dfs(neighbour, source, visited) == true) {
                    return true;
                }
            }
            else if(visited[neighbour] == true and neighbour != parent) {
                return true;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(vector<int>& edge: edges) {
            this->graph[edge[0]].push_back(edge[1]);
            this->graph[edge[1]].push_back(edge[0]);
            unordered_map<int,bool> visited;
            if(this->dfs(edge[0], -1, visited) == true) {
                return edge;
            }
        }
        return {};
    }
};