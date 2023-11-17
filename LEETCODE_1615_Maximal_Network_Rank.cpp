#include<bits/stdc++.h>
using namespace std;
int maximum(int& a, int b) {
    return (a > b) ? a : b;
}
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> neighbours;
        vector<vector<int>> connected = vector(n, vector<int>(n, 0));
        for(vector<int>& road: roads) {
            neighbours[road[0]]++;
            neighbours[road[1]]++;
            connected[road[0]][road[1]] = 1;
            connected[road[1]][road[0]] = 1;
        }
        int score = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                score = max(score, neighbours[i] + neighbours[j] - connected[i][j]);
            }
        }
        return score;
    }
};