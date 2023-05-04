#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,-1,0,1};
    int n = 0;
    int m = 0;
    bool bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        char base = grid[row][col];
        vis[row][col] = true;
        queue<vector<int>> q;       // {row,col,parent_row,parent_col}
        q.push({row,col,-1,-1});
        while(!q.empty()) {
            int r = q.front()[0], c = q.front()[1], pr = q.front()[2], pc = q.front()[3];
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = r + this->dr[i], ncol = c + this->dc[i];
                if(nrow >= 0 and nrow < this->n and ncol >= 0 and ncol < this->m) {
                    if(vis[nrow][ncol] == false and grid[nrow][ncol] == base) {
                        vis[nrow][ncol] = true;
                        q.push({nrow,ncol,r,c});
                    }
                    else if(vis[nrow][ncol] == true and grid[nrow][ncol] == base and nrow != pr and ncol != pc) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        this->n = grid.size(), this->m = grid[0].size();
        vector<vector<bool>> vis(this->n,vector<bool>(this->m,false));
        for(int i=0; i<this->n; i++) {
            for(int j=0; j<this->m; j++) {
                if(vis[i][j] == false) {
                    if(this->bfs(i,j,grid,vis) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};