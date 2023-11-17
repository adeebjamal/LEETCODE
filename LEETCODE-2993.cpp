#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(i == j) {
                    continue;
                }
                else if(grid[i][j] == 1) {
                    mp[j]++;
                }
                else {
                    mp[i]++;
                }
            }
        }
        for(int i = 0; i < grid.size(); i++) {
            if(mp[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};