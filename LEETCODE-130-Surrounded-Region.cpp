#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> drow = {-1,0,1,0};
    vector<int> dcol = {0,-1,0,1};
    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& board, int n, int m) {
        visited[row][col] = true;
        for(int i = 0; i < 4; i++) {
            int nrow = row + this->drow[i], ncol = col + this->dcol[i];
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m) {
                if(!visited[nrow][ncol] and board[nrow][ncol] == 'O') {
                    dfs(nrow,ncol,visited,board,n,m);
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        // traversing first and last row
        for(int j = 0; j < m; j++) {
            if(!visited[0][j] and board[0][j] == 'O') {
                dfs(0,j,visited,board,n,m);
            }
            if(!visited[n-1][j] and board[n-1][j] == 'O') {
                dfs(n-1,j,visited,board,n,m);
            }
        }
        // traversing first and last column
        for(int i = 0; i < n; i++) {
            if(!visited[i][0] and board[i][0] == 'O') {
                dfs(i,0,visited,board,n,m);
            }
            if(!visited[i][m-1] and board[i][m-1] == 'O') {
                dfs(i,m-1,visited,board,n,m);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] and board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};