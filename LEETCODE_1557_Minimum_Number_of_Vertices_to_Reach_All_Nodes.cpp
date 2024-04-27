#include<bits/stdc++.h>
using namespace std;
class Solution {
    stack<int> st;
    vector<int> topo;
    void topo_sort(int& source, vector<bool>& visited, unordered_map<int, vector<int>>& graph) {
        visited[source] = true;
        for(int& neighbour: graph[source]) {
            if(visited[neighbour] == false) {
                this->topo_sort(neighbour, visited, graph);
            }
        }
        this->st.push(source);
    }
    void bfs(int& source, vector<bool>& visited, unordered_map<int, vector<int>>& graph) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(q.empty() == false) {
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
    public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for(vector<int>& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<bool> visited(n, false);
        for(int node = 0; node < n; node++) {
            if(visited[node] == false) {
                this->topo_sort(node, visited, graph);
            }
        }
        while(this->st.empty() == false) {
            this->topo.push_back(this->st.top());
            this->st.pop();
        }
        for(int node = 0; node < n; node++) {
            visited[node] = false;
        }
        vector<int> answer;
        for(int& node: this->topo) {
            if(visited[node] == false) {
                answer.push_back(node);
                this->bfs(node, visited, graph);
            }
        }
        return answer;
    }
};