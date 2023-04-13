// https://leetcode.com/problems/number-of-islands/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void bfs(int& row, int& col, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        visited[row][col] = true;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()) {
            int curr_row = q.front().first, curr_col = q.front().second;
            q.pop();
            for(int delrow = -1; delrow <= 1; delrow++) {
                for(int delcol = -1; delcol <= 1; delcol++) {
                    int newrow = curr_row + delrow, newcol = curr_col + delcol;
                    if(newrow>=0 and newrow<grid.size() and newcol>=0 and newcol<grid[0].size()) {
                        if(!visited[newrow][newcol] and grid[newrow][newcol] == '1') {
                            if(!(newrow != curr_row and newcol != curr_col)) {
                                visited[newrow][newcol] = true;
                                q.push({newrow,newcol});
                            }
                        }
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
        for(int row=0; row<grid.size(); row++) {
            for(int col=0; col<grid[0].size(); col++) {
                if(visited[row][col] == false and grid[row][col] == '1') {
                    count++;
                    bfs(row, col, visited, grid);
                }
            }
        }
        return count;
    }
};