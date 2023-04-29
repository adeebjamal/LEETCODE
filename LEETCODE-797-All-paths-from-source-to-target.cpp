#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> answer;
    int n = 0;
    void dfs(vector<vector<int>>& graph, vector<int>& path, int current) {
        if(current == this->n - 1) {
            this->answer.push_back(path);
            this->answer.back().push_back(current);
            return;
        }
        path.push_back(current);
        for(int& neighbour: graph[current]) {
            dfs(graph,path,neighbour);
        }
        path.pop_back();
    }
    public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->n = graph.size();
        vector<int> path;
        this->dfs(graph,path,0);
        return this->answer;
    }
};