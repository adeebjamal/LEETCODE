// https://leetcode.com/problems/01-matrix/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> answer(n,vector<int>(m,0));
        queue<vector<int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j,0});
                    visited[i][j] = 1;
                }
            }
        }
        int drow[] = {-1,0,1,0}, dcol[] = {0,1,0,-1};
        while(!q.empty()) {
            int row = q.front()[0], col = q.front()[1], steps = q.front()[2];
            q.pop();
            answer[row][col] = steps;
            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i], ncol = col + dcol[i];
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and visited[nrow][ncol] == 0) {
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol,steps+1});
                }
            }
        }
        return answer;
    }
};