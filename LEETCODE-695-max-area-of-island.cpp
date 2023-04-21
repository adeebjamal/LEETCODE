// https://leetcode.com/problems/max-area-of-island/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,-1,0,1};
    int n = 0;
    int m = 0;
    int bfs(int& row, int& col, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = true;
        int area = 1;
        while(!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = r + this->dr[i], ncol = c + this->dc[i];
                if(nrow >= 0 and nrow < this->n and ncol >= 0 and ncol < this->m) {
                    if(vis[nrow][ncol] == false and grid[nrow][ncol] == 1) {
                        area++;
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = true;
                    }
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->n = grid.size(), this->m = grid[0].size();
        int answer = 0;
        vector<vector<bool>> vis(this->n,vector<bool>(this->m,false));
        for(int i=0; i<this->n; i++) {
            for(int j=0; j<this->m; j++) {
                if(vis[i][j] == false and grid[i][j] == 1) {
                    answer = max(answer,this->bfs(i,j,grid,vis));
                }
            }
        }
        return answer;
    }
};
int main() {
    Solution* obj = new Solution();
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout<<obj->maxAreaOfIsland(grid)<<endl;
    return 0;
}