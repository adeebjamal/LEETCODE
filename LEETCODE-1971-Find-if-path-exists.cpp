// https://leetcode.com/problems/find-if-path-exists-in-graph/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> sequence;
public:
    void dfs(int source, unordered_map<int,vector<int>>& adj, vector<bool>& visited) {
        this->sequence.push_back(source);
        visited[source] = true;
        for(int& neighbour: adj[source]) {
            if(visited[neighbour] == false) {
                dfs(neighbour,adj,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(n,false);
        for(vector<int>& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // Call the dfs function only once and it will traverse only the component in which the source is present. If destination id also present in that component then there is a path between source and destination and is destination is present in some other component then path does not exists between source and destination.
        dfs(source,adj,visited);
        for(int& node: this->sequence) {
            if(node == destination) {
                return true;
            }
        }
        return false;
    }
};