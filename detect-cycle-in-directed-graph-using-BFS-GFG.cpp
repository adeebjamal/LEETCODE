// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int,int> indegree;
        for(int node=0; node<V; node++) {
            for(int& neighbour: adj[node]) {
                indegree[neighbour]++;
            }
        }
        queue<int> q;
        for(int node=0; node<V; node++) {
            if(indegree[node] == 0) {
                q.push(node);
            }
        }
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for(int& neighbout: adj[node]) {
                indegree[neighbout]--;
                if(indegree[neighbout] == 0) {
                    q.push(neighbout);
                }
            }
        }
        return count != V;
    }
};