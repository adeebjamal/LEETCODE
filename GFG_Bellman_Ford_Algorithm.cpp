#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> distance(V, 1e8);
        distance[S] = 0;
        for(int i = 0; i < V-1; i++) {
            for(vector<int>& edge: edges) {
                if(distance[edge[0]] != 1e8 and distance[edge[0]] + edge[2] < distance[edge[1]]) {
                    distance[edge[1]] = distance[edge[0]] + edge[2];
                }
            }
        }
        // One more iteration to check for negative cycle
        for(vector<int>& edge: edges) {
            if(distance[edge[0]] != 1e8 and distance[edge[0]] + edge[2] < distance[edge[1]]) {
                return {-1};
            }
        }
        return distance;
    }
};