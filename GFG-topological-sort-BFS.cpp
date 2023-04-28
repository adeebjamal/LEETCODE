#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[]) {
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
    vector<int> answer;
    while(!q.empty()) {
        answer.push_back(q.front());
        for(int& neighbour: adj[q.front()]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
        q.pop();
    }
    return answer;
}