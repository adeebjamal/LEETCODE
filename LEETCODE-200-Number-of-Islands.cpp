// https://leetcode.com/problems/number-of-islands/description/
#include<bits/stdc++.h>
using namespace std;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
class Solution {
public:
    void bfs(int& row, int& col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = true;
        while(!q.empty()) {
            int curr_row = q.front().first, curr_col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int newrow = curr_row + dr[i], newcol = curr_col + dc[i];
                if(newrow >= 0 and newrow < grid.size() and newcol >= 0 and newcol < grid[0].size()) {
                    if(visited[newrow][newcol] == false and grid[newrow][newcol] == '1') {
                        q.push({newrow,newcol});
                        visited[newrow][newcol] = true;
                    }
                }
            }
        }
    }
    void dfs(int& row, int& col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        for(int i=0; i<4; i++) {
            int newrow = row + dr[i], newcol = col + dc[i];
            if(newrow >= 0 and newrow < grid.size() and newcol >= 0 and newcol < grid[0].size()) {
                if(visited[newrow][newcol] == false and grid[newrow][newcol] == '1') {
                    this->dfs(newrow,newcol,grid,visited);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int count = 0;
        for(int row=0; row<grid.size(); row++) {
            for(int col=0; col<grid[0].size(); col++) {
                if(visited[row][col] == false and grid[row][col] == '1') {
                    count++;
                    this->dfs(row,col,grid,visited);
                    // this->bfs(row,col,grid,visited);
                }
            }
        }
        return count;
    }
};