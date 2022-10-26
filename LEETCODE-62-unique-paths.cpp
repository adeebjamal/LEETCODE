/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move
either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to
reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 1e9.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int mod=2*1e9;
public:
    int solve(vector<vector<int>>& dp, int row, int col) {
        if(row==0 and col==0) return 1;
        if(row<0 or col<0) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int up=solve(dp,row-1,col);
        int left=solve(dp,row,col-1);
        return dp[row][col]=(up%mod + left%mod)%mod;
    }
    int solve(int m, int n) {
        int dp[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 and j==0) {
                    dp[i][j]=1;
                }
                else {
                    int up=0, left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans1=solve(dp,m-1,n-1), ans2=solve(m,n);
        if(ans1==ans2) {
            return ans1;
        }
        return -1;
    }
};
int main() {
    Solution* obj;
    cout<<obj->uniquePaths(3,2);
    cout<<obj->uniquePaths(3,7);
    return 0;
}