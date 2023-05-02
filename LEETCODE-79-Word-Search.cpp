// https://leetcode.com/problems/word-search/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int n = 0;
    int m = 0;
    int len = 0;
    bool dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& vis, string& word, int index) {
        if(index == this->len) {
            return true;
        }
        if(row < 0 or col < 0 or row == this->n or col == this->m) {
            return false;
        }
        if(board[row][col] != word[index] or vis[row][col] == true) {
            return false;
        }
        vis[row][col] = true;
        bool op1 = this->dfs(row+1,col,board,vis,word,index+1);
        bool op2 = this->dfs(row-1,col,board,vis,word,index+1);
        bool op3 = this->dfs(row,col+1,board,vis,word,index+1);
        bool op4 = this->dfs(row,col-1,board,vis,word,index+1);
        vis[row][col] = false;
        return op1 or op2 or op3 or op4;
    }
    public:
    bool exist(vector<vector<char>>& board, string word) {
        this->n = board.size(), this->m = board[0].size(), this->len = word.length();
        for(int i=0; i<this->n; i++) {
            for(int j=0; j<this->m; j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<bool>> vis(this->n,vector<bool>(this->m,false));
                    if(this->dfs(i,j,board,vis,word,0) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main() {
    Solution* obj = new Solution();
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<obj->exist(board,"ABCB")<<endl;
    return 0;
}