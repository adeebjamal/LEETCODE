#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int,vector<int>> graph;
        for(int node = 0; node < edges.size(); node++) {
            graph[edges[node]].push_back(node);
        }
        unsigned long long int max_score = 0;
        int answer = -1;
        for(int node = 0; node < edges.size(); node++) {
            unsigned long long int score = accumulate(graph[node].begin(), graph[node].end(), 0LL);
            if(score > max_score) {
                max_score = score;
                answer = node;
            }
        }
        return answer;
    }
};