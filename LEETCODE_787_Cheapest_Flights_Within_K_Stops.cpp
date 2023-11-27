#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for(vector<int>& flight: flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> costs(n, 1e9);
        q.push({0, {src, 0}});
        costs[src] = 0;
        while(q.empty() == false) {
            int stops = q.front().first, node = q.front().second.first, cost = q.front().second.second;
            q.pop();
            for(pair<int,int>& neighbour: graph[node]) {
                int adjnode = neighbour.first, edgeweight = neighbour.second;
                if(cost + edgeweight < costs[adjnode] and stops <= k) {
                    costs[adjnode] = cost + edgeweight;
                    q.push({stops+1, {adjnode, costs[adjnode]}});
                }
            }
        }
        return (costs[dst] != 1e9) ? costs[dst] : -1;
    }
};