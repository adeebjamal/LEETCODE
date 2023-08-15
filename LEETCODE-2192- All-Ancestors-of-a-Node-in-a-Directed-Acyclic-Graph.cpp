#include<bits/stdc++.h>
using namespace std;
class Solution {
    void bfs(int& source, unordered_map<int,vector<int>>& adj, vector<bool>& visited, vector<set<int>>& answer) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node != source) {
                answer[node].insert(source);
            }
            for(int& child: adj[node]) {
                if(visited[child] == false) {
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(vector<int>& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<set<int>> answer;
        for(int i=0; i<n; i++) {
            set<int> temp;
            answer.push_back(temp);
        }
        for(int source=0; source<n; source++) {
            vector<bool> visited(n,false);
            this->bfs(source,adj,visited,answer);
        }
        vector<vector<int>> result;
        for(set<int>& st: answer) {
            result.push_back(vector<int>(st.begin(),st.end()));
        }
    }
};