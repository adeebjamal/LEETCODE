#include<bits/stdc++.h>
using namespace std;
class Solution2 {
public:
    void bfs(int& source, vector<vector<int>>& graph, vector<bool>& vis) {
        queue<int> q;
        q.push(source);
        vis[source] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int i=0; i<graph[node].size(); i++) {
                if(graph[node][i] == 1 and vis[i] == false) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);
        int answer = 0;
        for(int i=0; i<n; i++) {
            if(vis[i] == false) {
                answer++;
                this->bfs(i,isConnected,vis);
            }
        }
        return answer;
    }
};
class Solution {
public:
    void dfs(int& source, unordered_map<int,vector<int>>& graph, vector<bool>& visited) {
        visited[source] = true;
        for(int& neighbour: graph[source]) {
            if(visited[neighbour] == false) {
                this->dfs(neighbour,graph,visited);
            }
        }
    }
    void bfs(int& source, unordered_map<int,vector<int>>& graph, vector<bool>& visited) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int& neighbour: graph[node]) {
                if(visited[neighbour] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> graph;
        for(int i=0; i<isConnected.size(); i++) {
            for(int j=0; j<isConnected[0].size(); j++) {
                if(isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int nodes = isConnected.size(), answer = 0;
        vector<bool> visited(nodes,false);
        for(int node=0; node<nodes; node++) {
            if(visited[node] == false) {
                answer++;
                this->bfs(node,graph,visited);
                // this->dfs(node,graph,visited);
            }
        }
        return answer;
    }
};