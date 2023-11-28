#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for(vector<int>& road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        priority_queue<pair<unsigned long long int,int>, vector<pair<unsigned long long int,int>>, greater<pair<unsigned long long int,int>>> pq;
        vector<unsigned long long int> distance(n, 1e18);
        vector<int> ways(n, 0);
        distance[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        int mod = 1e9 + 7;
        while(pq.empty() == false) {
            unsigned long long int dist = pq.top().first, node = pq.top().second;
            pq.pop();
            for(pair<int,int>& edge: graph[node]) {
                int neighbour = edge.first, edgeweight = edge.second;
                if(dist + edgeweight < distance[neighbour]) {
                    distance[neighbour] = dist + edgeweight;
                    pq.push({distance[neighbour], neighbour});
                    ways[neighbour] = ways[node];
                }
                else if(dist + edgeweight == distance[neighbour]) {
                    ways[neighbour] = (ways[neighbour] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};