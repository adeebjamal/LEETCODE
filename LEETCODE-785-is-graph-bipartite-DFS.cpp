#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int start, int col, vector<vector<int>>& graph, vector<int>& color) {
        color[start] = col;
        for(int& neighbour: graph[start]) {
            if(color[neighbour] == -1) {
                if(dfs(neighbour,!col,graph,color) == false) {
                    return false;
                }
            }
            else if(color[neighbour] == color[start]) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                if(dfs(i,0,graph,color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};