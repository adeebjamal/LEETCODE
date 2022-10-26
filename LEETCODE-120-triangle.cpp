/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on
index i on the current row, you may move to either index i or index i + 1 on the next row.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int row, int col, int rows, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(row==rows-1) return triangle[rows-1][col];
        if(dp[row][col] != -1) return dp[row][col];
        int down=triangle[row][col] + solve(row+1,col,rows,triangle,dp);
        int diagonal=triangle[row][col] + solve(row+1,col+1,rows,triangle,dp);
        return dp[row][col]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        vector<vector<int>> dp(rows,vector<int>(rows,-1));
        return solve(0,0,rows,triangle,dp);
    }
};
int main() {
    Solution* obj;
    vector<vector<int>> triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<obj->minimumTotal(triangle);
    return 0;
}