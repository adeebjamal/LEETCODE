#include<bits/stdc++.h>
using namespace std;
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
class Solution {
    int n = 0;
    int m = 0;
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        for(int i=0; i<4; i++) {
            int nrow = row + dr[i], ncol = col + dc[i];
            if(nrow >= 0 and ncol >= 0 and nrow < this->n and ncol < this->m) {
                if(grid[nrow][ncol] == 0 and visited[nrow][ncol] == false) {
                    this->dfs(nrow,ncol,grid,visited);
                }
            }
        }
    }
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = true;
        while(!q.empty()) {
            int crow = q.front().first, ccol = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = crow + dr[i], ncol = ccol + dc[i];
                if(nrow >= 0 and ncol >= 0 and nrow < this->n and ncol < this->m) {
                    if(grid[nrow][ncol] == 0 and visited[nrow][ncol] == false) {
                        q.push({nrow,ncol});
                        visited[nrow][ncol] = true;
                    }
                }
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        this->n = grid.size(), this->m = grid[0].size();
        vector<vector<bool>> visited(this->n,vector<bool>(this->m,false));
        // Traversing first and last rows
        for(int j=0; j<this->m; j++) {
            if(grid[0][j] == 0 and visited[0][j] == false) {
                // this->dfs(0,j,grid,visited);
                this->bfs(0,j,grid,visited);
            }
            if(grid[this->n-1][j] == 0 and visited[this->n-1][j] == false) {
                // this->dfs(this->n-1,j,grid,visited);
                this->bfs(this->n-1,j,grid,visited);
            }
        }
        // Traversing first and last columns
        for(int i=0; i<this->n; i++) {
            if(grid[i][0] == 0 and visited[i][0] == false) {
                // this->dfs(i,0,grid,visited);
                this->bfs(i,0,grid,visited);
            }
            if(grid[i][this->m-1] == 0 and visited[i][this->m-1] == false) {
                // this->dfs(i,this->m-1,grid,visited);
                this->bfs(i,this->m-1,grid,visited);
            }
        }
        // Counting closed islands
        int answer = 0;
        for(int i=0; i<this->n; i++) {
            for(int j=0; j<this->m; j++) {
                if(grid[i][j] == 0 and visited[i][j] == false) {
                    answer++;
                    // this->dfs(i,j,grid,visited);
                    this->bfs(i,j,grid,visited);
                }
            }
        }
        return answer;
    }
};