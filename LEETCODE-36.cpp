#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> rows, cols;
        map<pair<int,int>,unordered_set<char>> squares;
        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                if(board[r][c] == '.') {
                    continue;
                }
                if(rows[r].find(board[r][c]) != rows[r].end()) {
                    return false;
                }
                if(cols[c].find(board[r][c]) != cols[c].end()) {
                    return false;
                }
                if(squares[{r/3,c/3}].find(board[r][c]) != squares[{r/3,c/3}].end()) {
                    return false;
                }
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[{r/3,c/3}].insert(board[r][c]);
            }
        }
        return true;
    }
};