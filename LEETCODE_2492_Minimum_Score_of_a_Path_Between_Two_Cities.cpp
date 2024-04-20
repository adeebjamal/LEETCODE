#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for(vector<int>& road: roads) {
            graph[road[0] - 1].push_back({road[1] - 1, road[2]});
            graph[road[1] - 1].push_back({road[0] - 1, road[2]});
        }
        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        int answer = 1e9;
        q.push({0, 1e9});
        visited[0] = true;
        while(q.empty() == false) {
            int node = q.front().first, distance = q.front().second;
            q.pop();
            for(pair<int, int>& edge: graph[node]) {
                int neighbour = edge.first, edge_weight = edge.second;
                answer = min(answer, edge_weight);
                if(visited[neighbour] == false) {
                    q.push({neighbour, edge_weight});
                    visited[neighbour] = true;
                }
            }
        }
        return answer;
    }
};