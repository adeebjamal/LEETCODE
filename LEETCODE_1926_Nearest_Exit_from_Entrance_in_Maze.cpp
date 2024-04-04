#include<bits/stdc++.h>
using namespace std;
class Solution {
    int rows = 0, cols = 0;
    void bfs(int& answer, vector<int>& entrance, vector<vector<char>>& maze, vector<vector<bool>>& visited) {
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        visited[entrance[0]][entrance[1]] = true;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while(q.empty() == false) {
            int row = q.front()[0], col = q.front()[1], distance = q.front()[2];
            q.pop();
            for(int i = 0; i < 4; i++) {
                int new_row = row + dr[i], new_col = col + dc[i];
                if(new_row >= 0 and new_row < this->rows and new_col >= 0 and new_col < this->cols) {
                    if(new_row == 0 or new_row == this->rows - 1 or new_col == 0 or new_col == this->cols - 1) {
                        if(visited[new_row][new_col] == false and maze[new_row][new_col] == '.') {
                            answer = min(answer, distance + 1);
                        }
                    }
                    if(visited[new_row][new_col] == false and maze[new_row][new_col] == '.') {
                        q.push({new_row, new_col, distance + 1});
                        visited[new_row][new_col] = true;
                    }
                }
            }
        }
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        this->rows = maze.size(), this->cols = maze[0].size();
        vector<vector<bool>> visited(this->rows, vector<bool>(this->cols, false));
        int answer = INT_MAX;
        this->bfs(answer, entrance, maze, visited);
        return answer != INT_MAX ? answer : -1;
    }
};