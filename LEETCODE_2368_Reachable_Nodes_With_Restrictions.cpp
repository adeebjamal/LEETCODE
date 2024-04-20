#include<bits/stdc++.h>
using namespace std;
class Solution {
    int dfs(int source, unordered_map<int, vector<int>>& graph, unordered_set<int>& hash, vector<bool>& visited) {
        visited[source] = true;
        int answer = 1;
        for(int& neighbour: graph[source]) {
            if(visited[neighbour] == false and hash.find(neighbour) == hash.end()) {
                answer += this->dfs(neighbour, graph, hash, visited);
            }
        }
        return answer;
    }
    int bfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& hash, vector<bool>& visited) {
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int answer = 0;
        while(q.empty() == false) {
            int node = q.front();
            answer++;
            q.pop();
            for(int& neighbour: graph[node]) {
                if(visited[neighbour] == false and hash.find(neighbour) == hash.end()) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return answer;
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int, vector<int>> graph;
        for(vector<int>& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> hash(restricted.begin(), restricted.end());
        vector<bool> visited(n, false);
        // return this->bfs(graph, hash, visited);
        return this->dfs(0, graph, hash, visited);
    }
};