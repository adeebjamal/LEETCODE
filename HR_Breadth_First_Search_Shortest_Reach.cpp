#include<bits/stdc++.h>
using namespace std;
vector<int> f(int& N, int& source, unordered_map<int,vector<int>>& graph) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(N, 1e9);
    pq.push({0, source});
    distance[source] = 0;
    while(pq.empty() == false) {
        int node = pq.top().second, dist = pq.top().first;
        pq.pop();
        for(int& neighbour: graph[node]) {
            if(distance[neighbour] > distance[node] + 6) {
                distance[neighbour] = distance[node] + 6;
                pq.push({distance[neighbour], neighbour});
            }
        }
    }
    return distance;
}
int main() {
    int tc = 0;
    cin>>tc;
    while(tc--) {
        int nodes = 0, edges = 0, source = 0;
        cin>>nodes>>edges;
        unordered_map<int,vector<int>> graph;
        for(int i = 0; i < edges; i++) {
            int u = 0, v = 0;
            cin>>u>>v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        cin>>source;
        source--;
        vector<int> answer = f(nodes, source, graph);
        for(int& num: answer) {
            if(num == 1e9) {
                cout<<"-1 ";
            }
            else if(num == 0) {
                continue;
            }
            else {
                cout<<num<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}