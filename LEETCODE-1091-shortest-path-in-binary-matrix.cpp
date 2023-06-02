#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n == 1 and m == 1 and grid[0][0] == 0) {
            return 1;
        }
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<vector<int>> q;       // {row,col,dist}
        if(grid[0][0] == 0) {
            q.push({0,0,1});
            vis[0][0] = true;
        }
        while(!q.empty()) {
            int row = q.front()[0], col = q.front()[1], dist = q.front()[2];
            q.pop();
            for(int dr=-1; dr<=1; dr++) {
                for(int dc=-1; dc<=1; dc++) {
                    int nrow = row + dr, ncol = col + dc;
                    if(nrow >= 0 and ncol >= 0 and nrow < n and ncol < m) {
                        if(grid[nrow][ncol] == 0 and vis[nrow][ncol] == false) {
                            q.push({nrow,ncol,dist+1});
                            vis[nrow][ncol] = true;
                            if(nrow == n-1 and ncol == m-1) {
                                return dist+1;
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};