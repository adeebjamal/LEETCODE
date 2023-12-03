#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& distance, int& N) {
    for(int i = 1; i <= N; i++) {
        if(distance[i] == 1e9) {
            cout<<"-1 ";
        }
        else if(distance[i] == 0) {
            continue;
        }
        else {
            cout<<distance[i]<<" ";
        }
    }
    cout<<endl;
}
void f(int& N, int& source, unordered_map<int,vector<pair<int,int>>>& graph) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(N+1, 1e9);
    pq.push({0, source});
    distance[source] = 0;
    while(pq.empty() == false) {
        int node = pq.top().second, dist = pq.top().first;
        pq.pop();
        for(pair<int,int>& edge: graph[node]) {
            int adjnode = edge.first, edgeweight = edge.second;
            if(distance[adjnode] > dist + edgeweight) {
                distance[adjnode] = dist + edgeweight;
                pq.push({distance[adjnode], adjnode});
            }
        }
    }
    print(distance, N);
}
int main() {
    int tc = 0;
    cin>>tc;
    while(tc--) {
        int nodes = 0, edges = 0, source = 0;
        cin>>nodes>>edges;
        unordered_map<int,vector<pair<int,int>>> graph;
        for(int i = 0; i < edges; i++) {
            int u = 0, v = 0, x = 0;
            cin>>u>>v>>x;
            graph[u].push_back({v,x});
            graph[v].push_back({u,x});
        }
        cin>>source;
        f(nodes, source, graph);
    }
    return 0;
}