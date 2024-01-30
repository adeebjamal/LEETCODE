#include <bits/stdc++.h>
using namespace std;
class Solution {
    int max_steps = 0;
    unordered_map<string, int> dp;
    int f(int row, int col, int steps, int& rows, int& cols) {
        if(row < 0 or col < 0 or row >= rows or col >= cols) {
            return 1;
        }
        if(steps >= this->max_steps) {
            return 0;
        }
        string key = to_string(row) + "_" + to_string(col) + "_" + to_string(steps);
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }
        int mod = 1e9 + 7;
        int up = this->f(row - 1, col, steps + 1, rows, cols);
        int down = this->f(row + 1, col, steps + 1, rows, cols);
        int left = this->f(row, col - 1, steps + 1, rows, cols);
        int right = this->f(row, col + 1, steps + 1, rows, cols);
        return dp[key] = ((up % mod + down % mod) % mod + (left % mod + right % mod) % mod) % mod;
    }
    int f2(int row, int col, int steps, int& rows, int& cols, vector<vector<vector<int>>>& DP) {
        if(row < 0 or col < 0 or row >= rows or col >= cols) {
            return 1;
        }
        if(steps >= this->max_steps) {
            return 0;
        }
        if(DP[row][col][steps] != -1) {
            return DP[row][col][steps];
        }
        int mod = 1e9 + 7;
        int up = this->f(row - 1, col, steps + 1, rows, cols);
        int down = this->f(row + 1, col, steps + 1, rows, cols);
        int left = this->f(row, col - 1, steps + 1, rows, cols);
        int right = this->f(row, col + 1, steps + 1, rows, cols);
        return DP[row][col][steps] = ((up % mod + down % mod) % mod + (left % mod + right % mod) % mod) % mod;
    }
    public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->max_steps = maxMove;
        vector<vector<vector<int>>> DP(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        // return this->f(startRow, startColumn, 0, m, n);
        return this->f2(startRow, startColumn, 0, m, n, DP);
    }
};