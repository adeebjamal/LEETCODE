#include<bits/stdc++.h>
using namespace std;
int rows = 0;
int cols = 0;
int dp[1001][1001];
class Solution {
    bool check(int row, int col) {
        return row >= 0 and col >= 0 and row < rows and col < cols;
    }
    int f(int row, int col, vector<vector<int>>& grid) {
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        int one = 0, two = 0, three = 0;
        if(this->check(row - 1, col + 1) == true) {
            one = (grid[row - 1][col + 1] > grid[row][col]) ? 1 + this->f(row - 1, col + 1, grid) : 0;
        }
        if(this->check(row, col + 1) == true) {
            two = (grid[row][col + 1] > grid[row][col]) ? 1 + this->f(row, col + 1, grid) : 0;
        }
        if(this->check(row + 1, col + 1) == true) {
            three = (grid[row + 1][col + 1] > grid[row][col]) ? 1 + this->f(row + 1, col + 1, grid) : 0;
        }
        return dp[row][col] = max(one, max(two, three));
    }
    public:
    int maxMoves(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int answer = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < rows; i++) {
            answer = max(answer, this->f(i, 0, grid));
        }
        return answer;
    }
};