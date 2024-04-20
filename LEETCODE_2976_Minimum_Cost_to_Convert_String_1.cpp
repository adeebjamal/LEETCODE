#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> distance(26, vector<long long>(26, 1e18));
        for(int i = 0; i < 26; i++) {
            distance[i][i] = 0;
        }

        // forming the Graph
        int len = original.size();
        for(int i = 0; i < len; i++) {
            int u = original[i] - 'a', v = changed[i] - 'a';
            long long wt = cost[i];
            distance[u][v] = min(distance[u][v], wt);
        }

        // Floyd Warshall
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }

        long long answer = 0;
        len = source.length();
        for(int i = 0; i < len; i++) {
            int u = source[i] - 'a', v = target[i] - 'a';
            if(distance[u][v] == 1e18) {
                return -1;
            }
            answer += distance[u][v];
        }

        return answer;
    }
};