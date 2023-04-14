// https://leetcode.com/problems/rotting-oranges/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int fresh = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j,0});
                    visited[i][j] = true;
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int answer = 0;
        vector<int> drow = {-1,1,0,0}, dcol = {0,0,-1,1};
        while(q.empty() == false) {
            int row = q.front()[0], col = q.front()[1], time = q.front()[2];
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = row + drow[i], ncol = col + dcol[i];
                if(nrow>=0 and nrow<grid.size() and ncol>=0 and ncol<grid[0].size() and visited[nrow][ncol] == false and grid[nrow][ncol] == 1) {
                    q.push({nrow,ncol,time+1});
                    visited[nrow][ncol] = true;
                    answer = max(answer,time+1);
                    fresh--;
                }
            }
        }
        if(fresh != 0) {
            return -1;
        }
        return answer;
    }
};