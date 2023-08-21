#include<bits/stdc++.h>
using namespace std;
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
class Solution {
    int n = 0;
    int m = 0;
    void dfs(int& row, int& col, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        for(int i=0; i<4; i++) {
            int nrow = row + dr[i], ncol = col + dc[i];
            if(nrow >= 0 and nrow < this->n and ncol >= 0 and ncol < this->m) {
                if(visited[nrow][ncol] == false and board[nrow][ncol] == 'X') {
                    this->dfs(nrow,ncol,board,visited);
                }
            }
        }
    }
    void bfs(int& row, int& col, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = true;
        while(!q.empty()) {
            int curr_row = q.front().first, curr_col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = curr_row + dr[i], ncol = curr_col + dc[i];
                if(nrow >= 0 and nrow < this->n and ncol >= 0 and ncol < this->m) {
                    if(visited[nrow][ncol] == false and board[nrow][ncol] == 'X') {
                        q.push({nrow,ncol});
                        visited[nrow][ncol] = true;
                    }
                }
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        this->n = board.size(), this->m = board[0].size();
        vector<vector<bool>> visited(this->n,vector<bool>(this->m,false));
        int answer = 0;
        for(int i=0; i<this->n; i++) {
            for(int j=0; j<this->m; j++) {
                if(visited[i][j] == false and board[i][j] == 'X') {
                    answer++;
                    // this->dfs(i,j,board,visited);
                    this->bfs(i,j,board,visited);
                }
            }
        }
        return answer;
    }
};