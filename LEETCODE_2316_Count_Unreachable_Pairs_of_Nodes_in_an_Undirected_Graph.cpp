#include<bits/stdc++.h>
using namespace std;
class Solution {
    int bfs(int& source, vector<bool>& visited, unordered_map<int,vector<int>>& graph) {
        int count = 0;
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for(int& neighbour: graph[node]) {
                if(visited[neighbour] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return count;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        for(vector<int>& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int component_sizes = 0;
        vector<bool> visited(n,false);
        unsigned long long int answer = 0;
        for(int node = 0; node < n; node++) {
            if(visited[node] == false) {
                int size = this->bfs(node, visited, graph);
                answer += (component_sizes*1LL * size*1LL);
                component_sizes += size;
            }
        }
        return answer;
    }
};