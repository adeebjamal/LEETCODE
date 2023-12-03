#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int spanningTree(int V, int& source, unordered_map<int,vector<pair<int,int>>>& adj) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(V, false);
        pq.push({0,source});         // {weight, node}
        int sum = 0;
        while(pq.empty() == false) {
            int node = pq.top().second, weight = pq.top().first;
            pq.pop();
            if(visited[node] == true) {
                continue;
            }
            sum += weight;
            visited[node] = true;
            for(pair<int,int>& edge: adj[node]) {
                int adjnode = edge.first, edgeweight = edge.second;
                if(visited[adjnode] == false) {
                    pq.push({edgeweight, adjnode});
                }
            }
        }
        return sum;
    }
};
int main() {
    Solution* obj = new Solution();
    int nodes = 0, edges = 0;
    cin>>nodes>>edges;
    unordered_map<int,vector<pair<int,int>>> graph;
    for(int i = 0; i < edges; i++) {
        int u = 0, v = 0, w = 0;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int source = 0;
    cin>>source;
    cout<<obj->spanningTree(nodes, source, graph);
    return 0;
}