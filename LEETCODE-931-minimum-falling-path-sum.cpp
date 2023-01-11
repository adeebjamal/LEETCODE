#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rows=0, cols=0;
    int solve(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(col<0 or col>=cols) {
            return 1e7;
        }
        if(row==rows-1) {
            return matrix[row][col];
        }
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        int down=matrix[row][col]+solve(row+1,col,matrix,dp);
        int left_down=matrix[row][col]+solve(row+1,col-1,matrix,dp);
        int right_down=matrix[row][col]+solve(row+1,col+1,matrix,dp);
        return dp[row][col]=min(down,min(left_down,right_down));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        rows=matrix.size(), cols=matrix[0].size();
        int ans=INT_MAX;
        for(int col=0; col<cols; col++) {
            vector<vector<int>> dp(rows,vector<int>(cols,-1));
            ans=min(ans,solve(0,col,matrix,dp));
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> matrix={{2,1,3},{6,5,4},{7,8,9}};
    Solution* obj;
    cout<<obj->minFallingPathSum(matrix);
    return 0;
}