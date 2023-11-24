#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;         // node -> {weight, neighbour}
        for(vector<int>& t: times) {
            graph[t[0]-1].push_back({t[2], t[1]-1});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distance(n, 1e9);
        distance[k-1] = 0;
        pq.push({0, k-1});
        while(pq.empty() == false) {
            int node = pq.top().second, weight = pq.top().first;
            pq.pop();
            for(pair<int,int>& p: graph[node]) {
                int v = p.second, wt = p.first;
                if(distance[v] > distance[node] + wt) {
                    distance[v] = distance[node] + wt;
                    pq.push({distance[v], v});
                }
            }
        }
        int answer = 0;
        for(int& num: distance) {
            if(num == 1e9) {
                return -1;
            }
            answer = max(answer, num);
        }
        return answer;
    }
};