/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp,int row, int col) {
        if(row==0 and col==0) return grid[0][0];
        if(row<0 or col<0) return 10000;
        if(dp[row][col] != -1) return dp[row][col];
        int up=grid[row][col]+solve(grid,dp,row-1,col);
        int left=grid[row][col]+solve(grid,dp,row,col-1);
        return dp[row][col] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        //return solve(grid,dp,rows-1,cols-1);
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(i==0 and j==0) dp[i][j]=grid[i][j];
                else {
                    int up=grid[i][j], left=grid[i][j];
                    if(i>0) up+= dp[i-1][j];
                    else up+= 10000;
                    if(j>0) left+= dp[i][j-1];
                    else left+= 10000;
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[rows-1][cols-1];
    }
};
int main() {
    Solution* obj;
    vector<vector<int>> grid={{1,3,1},{1,5,1},{4,2,1}};
    cout<<obj->minPathSum(grid)<<endl;
    grid={{1,2,3},{4,5,6}};
    cout<<obj->minPathSum(grid);
    return 0;
}