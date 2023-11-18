#include<bits/stdc++.h>
using namespace std;
class Solution {
    int bfs(int& source, unordered_map<int,vector<int>>& graph, vector<int>& quiet) {
        unordered_map<int,bool> visited;
        queue<int> q;
        q.push(source);
        visited[source] = true;
        int quietness = INT_MAX, answer = -1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(quiet[node] < quietness) {
                quietness = quiet[node];
                answer = node;
            }
            for(int& neighbour: graph[node]) {
                if(visited[neighbour] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return answer;
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int,vector<int>> graph;
        for(vector<int>& pair: richer) {
            graph[pair[1]].push_back(pair[0]);
        }
        vector<int> answer;
        for(int person = 0; person < quiet.size(); person++) {
            answer.push_back(this->bfs(person, graph, quiet));
        }
        return answer;
    }
};