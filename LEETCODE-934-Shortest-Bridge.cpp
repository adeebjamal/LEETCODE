// https://leetcode.com/problems/shortest-bridge/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int n = 0;
    int m = 0;
    vector<pair<int,int>> first;
    vector<pair<int,int>> second;
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,-1,0,1};
    void dfs(int& row, int& col, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& island_number) {
        if(island_number == 1) {
            this->first.push_back({row,col});
        }
        else if(island_number == 2) {
            this->second.push_back({row,col});
        }
        vis[row][col] = true;
        for(int i=0; i<4; i++) {
            int nrow = row + dr[i], ncol = col + dc[i];
            if(nrow >= 0 and nrow < this->n and ncol >= 0 and ncol < this->m) {
                if(vis[nrow][ncol] == false and grid[nrow][ncol] == 1) {
                    dfs(nrow,ncol,grid,vis,island_number);
                }
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        this->n = grid.size(), this->m = grid[0].size();
        vector<vector<bool>> vis(this->n,vector<bool>(this->m,false));
        int island_number = 0;
        for(int i=0; i<this->n; i++) {
            for(int j=0; j<this->m; j++) {
                if(vis[i][j] == false and grid[i][j] == 1) {
                    island_number++;
                    this->dfs(i,j,grid,vis,island_number);
                }
            }
        }
        int answer = INT_MAX;
        for(pair<int,int>& p1: this->first) {
            for(pair<int,int>& p2: this->second) {
                answer = min(answer,abs(p1.first - p2.first) + abs(p1.second - p2.second) - 1);
            }
        }
        return answer;
    }
};