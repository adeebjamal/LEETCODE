#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        for(vector<int>& edge: edges) {
            mp[edge[1]]++;
        }
        int winner = -1, winner_count = 0;
        for(int i = 0; i < n; i++) {
            if(mp[i] == 0) {
                winner = i;
                winner_count++;
            }
        }
        return (winner_count == 1) ? winner : -1;
    }
};