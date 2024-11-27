#include<bits/stdc++.h>
using namespace std;
class Solution {
    string f(vector<vector<int>>& board) {
        string representation = "";
        for(vector<int>& row: board) {
            for(int& num: row) {
                representation.push_back(num + '0');
            }
        }
        return representation;
    }
    public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> endBoard = {{1, 2, 3}, {4, 5, 0}};
        unordered_set<string> visited;
        queue<pair<vector<vector<int>>, int>> q;
        q.push({board, 0});
        visited.insert(this->f(board));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while(q.empty() == false) {
            vector<vector<int>> currentBoard = q.front().first;
            int distance = q.front().second;
            if(currentBoard == endBoard) {
                return distance;
            }
            q.pop();
            for(int row = 0; row < 2; row++) {
                for(int col = 0; col < 3; col++) {
                    if(currentBoard[row][col] == 0) {
                        for(int i = 0; i < 4; i++) {
                            int newRow = row + dr[i], newCol = col + dc[i];
                            if(newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < 3) {
                                swap(currentBoard[row][col], currentBoard[newRow][newCol]);
                                string representation = this->f(currentBoard);
                                if(visited.find(representation) == visited.end()) {
                                    q.push({currentBoard, distance + 1});
                                    visited.insert(representation);
                                }
                                swap(currentBoard[row][col], currentBoard[newRow][newCol]);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};