#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        int answer=0;
        for(int i=0; i<rows-2; i++) {
            for(int j=0; j<cols-2; j++) {
                int current_sum=0;
                current_sum+= grid[i][j];
                current_sum+= grid[i][j+1];
                current_sum+= grid[i][j+2];
                current_sum+= grid[i+1][j+1];
                current_sum+= grid[i+2][j];
                current_sum+= grid[i+2][j+1];
                current_sum+= grid[i+2][j+2];
                answer=max(answer,current_sum);
            }
        }
        return answer;
    }
};