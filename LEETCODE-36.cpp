#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(vector<char>& row: board) {
            unordered_map<char,int> mp;
            for(char& digit: row) {
                if(digit != '.') {
                    mp[digit]++;
                }
                if(mp[digit] > 1) {
                    return false;
                }
            }
        }
        for(int j=0; j<board[0].size(); j++) {
            unordered_map<char,int> mp;
            for(vector<char>& row: board) {
                if(row[j] != '.') {
                    mp[row[j]]++;
                }
                if(mp[row[j]] > 1) {
                    return false;
                }
            }
        }
        vector<pair<int,int>> vec = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        for(pair<int,int>& p: vec) {
            for(int i=p.first; i<p.first+3; i++) {
                unordered_map<char,int> mp;
                for(int j=p.second; j<p.second+3; j++) {
                    if(board[i][j] != '.') {
                        mp[board[i][j]]++;
                    }
                    if(mp[board[i][j]] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};