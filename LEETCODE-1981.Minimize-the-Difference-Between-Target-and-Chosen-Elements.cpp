// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int dp[8000][71];
    int rows = 0;
    int cols = 0;
    int f(vector<vector<int>>& mat, int row, int sum, int& target) {
        if(row >= this->rows) {
            return abs(sum-target);
        }
        if(dp[sum][row] != -1) {
            return dp[sum][row];
        }
        int answer = INT_MAX;
        for(int col=0; col<this->cols; col++) {
            int result = this->f(mat, row+1, sum+mat[row][col], target);
            answer = min(answer,result);
            if(answer == 0) {
                break;
            }
        }
        return dp[sum][row] = answer;
    }
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(this->dp, -1, sizeof(dp));
        this->rows = mat.size(), this->cols = mat[0].size();
        return this->f(mat,0,0,target);
    }
};