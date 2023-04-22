// https://leetcode.com/problems/find-all-groups-of-farmland/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> answer;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(land[i][j] == 1) {
                    int row = i, col = j;
                    while(col+1 < m && land[row][col+1] == 1) {
                        col++;
                    }
                    while(row+1 < n && land[row+1][j] == 1) {
                        row++;
                    }
                    answer.push_back({i, j, row, col});
                    for(int k=i; k<=row; k++) {
                        for(int l=j; l<=col; l++) {
                            land[k][l] = 0;
                        }
                    }
                }
            }
        }
        return answer;
    }
};