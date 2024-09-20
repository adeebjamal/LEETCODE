#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool f(int row, int col, int health, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<vector<int>>>& dp) {
        if(row == grid.size() - 1 and col == grid[0].size() - 1 and health > 0) {
            return grid[row][col] == 1 and health == 1 ? false : true;
        }
        if(health <= 0 or row < 0 or col < 0 or row >= grid.size() or col >= grid[0].size()) {
            return false;
        }
        if(visited[row][col] == true) {
            return false;
        }
        if(dp[row][col][health] != -1) {
            return dp[row][col][health];
        }
        visited[row][col] = true;
        bool up = this->f(row - 1, col, health - grid[row][col], grid, visited, dp);
        bool down = this->f(row + 1, col, health - grid[row][col], grid, visited, dp);
        bool left = this->f(row, col - 1, health - grid[row][col], grid, visited, dp);
        bool right = this->f(row, col + 1, health - grid[row][col], grid, visited, dp);
        visited[row][col] = false;
        return dp[row][col][health] = up or down or left or right;
    }
    public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(health + 1, -1)));
        return this->f(0, 0, health, grid, visited, dp);
    }
};