#include<bits/stdc++.h>
using namespace std;
class Solution {
    int rows = 0, cols = 0, answer = 0;
    vector<int> dr = {-1, 0, 1, 0}, dc = {0, -1, 0, 1};
    void update(int& row, int& col, vector<vector<int>>& grid) {
        for(int i = 0; i < 4; i++) {
            int new_row = row + this->dr[i], new_col = col + this->dc[i];
            if(!(new_row >= 0 and new_row < this->rows and new_col >= 0 and new_col < this->cols)) {
                this->answer++;
            }
            else if(grid[new_row][new_col] == 0) {
                this->answer++;
            }
        }
    }
    void dfs(int& row, int& col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        this->update(row, col, grid);
        for(int i = 0; i < 4; i++) {
            int new_row = row + this->dr[i], new_col = col + this->dc[i];
            if(new_row >= 0 and new_row < this->rows and new_col >= 0 and new_col < this->cols) {
                if(visited[new_row][new_col] == false and grid[new_row][new_col] == 1) {
                    this->dfs(new_row, new_col, grid, visited);
                }
            }
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        this->rows = grid.size(), this->cols = grid[0].size();
        vector<vector<bool>> visited(this->rows, vector<bool>(this->cols, false));
        for(int i = 0; i < this->rows; i++) {
            for(int j = 0; j < this->cols; j++) {
                if(visited[i][j] == false and grid[i][j] == 1) {
                    this->dfs(i, j, grid, visited);
                }
            }
        }
        return this->answer;
    }
};