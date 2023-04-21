// https://leetcode.com/problems/count-servers-that-communicate/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int n = 0;
    int m = 0;
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,-1,0,1};
    void bfs(int& row, int& col, vector<vector<int>>& grid, int& count) {
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = 0;
        while(!q.empty()) {
            count++;
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int j=0; j<this->m; j++) {
                if(grid[r][j] == 1) {
                    grid[r][j] = 0;
                    q.push({r,j});
                }
            }
            for(int i=0; i<this->n; i++) {
                if(grid[i][c] == 1) {
                    grid[i][c] = 0;
                    q.push({i,c});
                }
            }
        }
    }
public:
    int countServers(vector<vector<int>>& grid) {
        this->n = grid.size(), m = grid[0].size();
        int answer = 0;
        for(int i=0; i<this->n; i++) {
            for(int j=0; j<this->m; j++) {
                if(grid[i][j] == 1) {
                    int count = 0;
                    this->bfs(i,j,grid,count);
                    if(count > 1) {
                        answer+= count;
                    }
                }
            }
        }
        return answer;
    }
};