#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        unordered_map<int, priority_queue<pair<int, int>>> graph;
        int n = vals.size(), maxi = INT_MIN;
        for(int node = 0; node < n; node++) {
            maxi = max(maxi, vals[node]);
        }
        if(edges.empty() == true) {
            return maxi;
        }
        for(vector<int>& e: edges) {
            graph[e[0]].push({vals[e[1]], e[1]});
            graph[e[1]].push({vals[e[0]], e[0]});
        }
        for(int node = 0; node < n; node++) {
            int sum = vals[node], count = 1;
            while(graph[node].empty() == false and count <= k) {
                sum += graph[node].top().first;
                graph[node].pop();
                count++;
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};