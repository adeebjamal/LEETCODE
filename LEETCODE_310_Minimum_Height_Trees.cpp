#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1 and edges.size() == 0) {
            return {0};
        }
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(n, false);
        for(vector<int>& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        } 
        queue<int> q;
        for(int node = 0; node < n; node++) {
            if(indegree[node] == 1) {
                q.push(node);
            }
        }
        vector<int> answer;
        int remaining = n;
        while(q.empty() == false) {
            int q_size = q.size();
            remaining -= q_size;
            for(int i = 0; i < q_size; i++) {
                int node = q.front();
                q.pop();
                if(remaining == 0) {
                    answer.push_back(node);
                }
                for(int& child: graph[node]) {
                    indegree[child]--;
                    if(indegree[child] == 1) {
                        q.push(child);
                    }
                }
            }
        }
        return answer;
    }
};