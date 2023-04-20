#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        color[start] = 0;
        q.push(start);
        while(!q.empty()) {
            for(int& neighbour: graph[q.front()]) {
                if(color[neighbour] == -1) {
                    color[neighbour] = !color[q.front()];
                    q.push(neighbour);
                }
                else if(color[neighbour] == color[q.front()]) {
                    return false;
                }
            }
            q.pop();
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int node=0; node<n; node++) {
            if(color[node] == -1) {
                if(this->bfs(node,graph,color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};