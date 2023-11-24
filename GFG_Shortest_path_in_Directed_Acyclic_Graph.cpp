#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int& source, vector<bool>& visited, stack<int>& st, unordered_map<int,vector<pair<int,int>>>& graph) {
        visited[source] = true;
        for(pair<int,int>& edge: graph[source]) {
            if(visited[edge.first] == false) {
                this->dfs(edge.first, visited, st, graph);
            }
        }
        st.push(source);
    }
    public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){
        unordered_map<int,vector<pair<int,int>>> graph;
        for(vector<int>& edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<bool> visited(N, false);
        stack<int> st;
        for(int node = 0; node < N; node++) {
            if(visited[node] == false) {
                this->dfs(node, visited, st, graph);
            }
        }
        vector<int> distance(N, 1e9);
        distance[0] = 0;
        while(st.empty() == false) {
            int node = st.top();
            st.pop();
            for(pair<int,int>& edge: graph[node]) {
                int v = edge.first, wt = edge.second;
                distance[v] = min(distance[v], distance[node] + wt);
            }
        }
        for(int& num: distance) {
            if(num == 1e9) {
                num = -1;
            }
        }
        return distance;
    }
};