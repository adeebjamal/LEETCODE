/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents
the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int row, int col1, int col2, int rows, int cols, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(col1<0 or col2<0 or col1>=cols or col2>=cols) return -1e8;
        if(row==rows-1) {
            if(col1==col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
        int maxi=INT_MIN;
        for(int dj1=-1; dj1<=1; dj1++) {
            for(int dj2=-1; dj2<=1; dj2++) {
                int value=0;
                if(col1==col2) value=grid[row][col1];
                else value=grid[row][col1] + grid[row][col2];
                value+= solve(row+1, col1+dj1, col2+dj2, rows, cols, grid, dp);
                maxi=max(maxi,value);
            }
        }
        return dp[row][col1][col2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        vector<vector<vector<int>>> dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
        return solve(0,0,cols-1,rows,cols,grid,dp);
    }
};
int main() {
    Solution* obj;
    vector<vector<int>> grid={{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout<<obj->cherryPickup(grid)<<endl;
    grid={{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
    cout<<obj->cherryPickup(grid);
    return 0;
}