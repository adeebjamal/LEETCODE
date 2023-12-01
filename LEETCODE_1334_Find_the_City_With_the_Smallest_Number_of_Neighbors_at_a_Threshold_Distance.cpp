#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, 1e9));
        for(vector<int>& edge: edges) {
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }
        for(int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }
        // Floyd Warshal Algorithm
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(distance[i][k] == 1e9 or distance[k][j] == 1e9) {
                        continue;
                    }
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        // Done
        int cityCount = n, answerCity = -1;
        for(int city = 0; city < n; city++) {
            int count = 0;
            for(int adjcity = 0; adjcity < n; adjcity++) {
                if(distance[city][adjcity] <= distanceThreshold) {
                    count++;
                }
            }
            if(count <= cityCount) {
                cityCount = count;
                answerCity = city;
            }
        }
        return answerCity;
    }
};