/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot
can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot
include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int mod=2*1e9;
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& mat, int row, int col) {
        if(row>=0 and col>=0 and mat[row][col]==1) return 0;
        if(row<0 or col<0) return 0;
        if(row==0 and col==0) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int up=0, left=0;
        if(row>0) up=solve(dp,mat,row-1,col);
        if(col>0) left=solve(dp,mat,row,col-1);
        return dp[row][col]=(up%mod + left%mod)%mod;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size(), cols=obstacleGrid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        return solve(dp,obstacleGrid,rows-1,cols-1);
    }
};
int main() {
    Solution* obj;
    vector<vector<int>> mat={{0,0,0},{0,1,0},{0,0,0}};
    cout<<obj->uniquePathsWithObstacles(mat)<<endl;
    mat={{0,1},{0,0}};
    cout<<obj->uniquePathsWithObstacles(mat)<<endl;
    mat={{0}};
    cout<<obj->uniquePathsWithObstacles(mat)<<endl;
    mat={{1}};
    cout<<obj->uniquePathsWithObstacles(mat);
    return 0;
}