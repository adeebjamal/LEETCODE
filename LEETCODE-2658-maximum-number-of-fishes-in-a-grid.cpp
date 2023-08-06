#include<bits/stdc++.h>
using namespace std;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
class Solution {
public:
    void dfs(int& row, int& col, int& fishes, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        fishes+= grid[row][col];
        for(int i=0; i<4; i++) {
            int nrow = row + dr[i], ncol = col + dc[i];
            if(nrow >= 0 and ncol >= 0 and nrow < grid.size() and ncol < grid[0].size()) {
                if(visited[nrow][ncol] == false and grid[nrow][ncol] > 0) {
                    this->dfs(nrow,ncol,fishes,grid,visited);
                }
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size()));
        int answer = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(visited[i][j] == false and grid[i][j] > 0) {
                    int fishes = 0;
                    this->dfs(i,j,fishes,grid,visited);
                    answer = max(answer,fishes);
                }
            }
        }
        return answer;
    }
};