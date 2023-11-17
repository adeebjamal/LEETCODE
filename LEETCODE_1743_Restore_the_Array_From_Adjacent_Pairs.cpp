#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> answer;
    void dfs(unordered_map<int,vector<int>>& graph, int source, unordered_map<int,bool>& vis) {
        vis[source] = true;
        this->answer.push_back(source);
        for(int& neighbour: graph[source]) {
            if(vis[neighbour] == false) {
                this->dfs(graph, neighbour, vis);
            }
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> graph;
        for(vector<int>& pair: adjacentPairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        int source = 0;
        for(auto& itr: graph) {
            if(itr.second.size() == 1) {
                source = itr.first;
                break;
            }
        }
        unordered_map<int,bool> vis;
        this->dfs(graph, source, vis);
        return this->answer;
    }
};