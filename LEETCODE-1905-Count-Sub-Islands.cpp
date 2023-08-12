#include<bits/stdc++.h>
using namespace std;
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
class Solution {
    int n = 0;
    int m = 0;
    void dfs(int& row, int& col, int& flag, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        if(grid1[row][col] == 0) {
            flag = 0;
            // return;
            // Don't return, we need to traverse the entire component. Otherwise the remaining part will be traversed later and can get counted as valid sub island.
        }
        for(int i=0; i<4; i++) {
            int nrow = row + dr[i], ncol = col + dc[i];
            if(nrow >= 0 and ncol >= 0 and nrow < this->n and ncol < this->m) {
                if(visited[nrow][ncol] == false and grid2[nrow][ncol] == 1) {
                    this->dfs(nrow,ncol,flag,grid1,grid2,visited);
                }
            }
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        this->n = grid1.size(), this->m = grid1[0].size();
        vector<vector<bool>> visited(this->n,vector<bool>(this->m,false));
        int answer = 0;
        for(int i=0; i<this->n; i++) {
            for(int j=0; j<this->m; j++) {
                if(visited[i][j] == false and grid2[i][j] == 1) {
                    int flag = 1;
                    this->dfs(i,j,flag,grid1,grid2,visited);
                    answer+= flag;
                }
            }
        }
        return answer;
    }
};