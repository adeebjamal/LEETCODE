#include<bits/stdc++.h>
using namespace std;
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        for(int i=0; i<4; i++) {
            int nrow = row + dr[i], ncol = col + dc[i];
            if(nrow >= 0 and ncol >= 0 and nrow < board.size() and ncol < board[0].size()) {
                if(board[nrow][ncol] == 'O' and visited[nrow][ncol] == false) {
                    this->dfs(nrow,ncol,board,visited);
                }
            }
        }
    }
    void bfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = true;
        while(!q.empty()) {
            int crow = q.front().first, ccol = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = crow + dr[i], ncol = ccol + dc[i];
                if(nrow >= 0 and ncol >= 0 and nrow < board.size() and ncol < board[0].size()) {
                    if(visited[nrow][ncol] == false and board[nrow][ncol] == 'O') {
                        q.push({nrow,ncol});
                        visited[nrow][ncol] = true;
                    }
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        // traversing first and last row
        for(int col=0; col<m; col++) {
            if(board[0][col] == 'O' and visited[0][col] == false) {
                // this->dfs(0,col,board,visited);
                this->bfs(0,col,board,visited);
            }
            if(board[n-1][col] == 'O' and visited[n-1][col] == false) {
                // this->dfs(n-1,col,board,visited);
                this->bfs(n-1,col,board,visited);
            }
        }
        // traversing first and last column
        for(int row=0; row<n; row++) {
            if(board[row][0] == 'O' and visited[row][0] == false) {
                // this->dfs(row,0,board,visited);
                this->bfs(row,0,board,visited);
            }
            if(board[row][m-1] == 'O' and visited[row][m-1] == false) {
                // this->dfs(row,m-1,board,visited);
                this->bfs(row,m-1,board,visited);
            }
        }
        // Replacing O with X
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(visited[i][j] == false) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};