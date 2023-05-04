// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int node, unordered_map<int,vector<pair<int,int>>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[node] = true;
        for(pair<int,int>& p: adj[node]) {
            if(vis[p.first] == false) {
                this->dfs(p.first,adj,vis,st);
            }
        }
        st.push(node);
    }
    public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0; i<M; i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        vector<bool> vis(N,false);
        stack<int> st;
        for(int i=0; i<N; i++) {
            if(vis[i] == false) {
                this->dfs(i,adj,vis,st);
            }
        }
        vector<int> dist(N,1e9);
        dist[0] = 0;
        while(!st.empty()) {
            for(pair<int,int>& p: adj[st.top()]) {
                int v = p.first, wt = p.second;
                dist[v] = min(dist[v],dist[st.top()]+wt);
            }
            st.pop();
        }
        for(int& num: dist) {
            if(num == 1e9) {
                num = -1;
            }
        }
        return dist;
    }
};