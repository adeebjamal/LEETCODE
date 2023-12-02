#include<bits/stdc++.h>
using namespace std;
class Solution {
	public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(V, false);
        pq.push({0,0});         // {weight, node}
        int sum = 0;
        while(pq.empty() == false) {
            int node = pq.top().second, weight = pq.top().first;
            pq.pop();
            if(visited[node] == true) {
                continue;
            }
            sum += weight;
            visited[node] = true;
            for(vector<int>& edge: adj[node]) {
                int adjnode = edge[0], edgeweight = edge[1];
                if(visited[adjnode] == false) {
                    pq.push({edgeweight, adjnode});
                }
            }
        }
        return sum;
    }
};