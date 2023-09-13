#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,-1,0,1};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> distance(rows,vector<int>(cols,-1));
        queue<pair<int,int>> q;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                    distance[i][j] = 0;
                }
            }
        }
        int answer = -1;
        while(!q.empty()) {
            int curr_row = q.front().first, curr_col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int new_row = curr_row + this->dr[i], new_col = curr_col + this->dc[i];
                if(new_row >= 0 and new_row < rows and new_col >= 0 and new_col < cols) {
                    if(distance[new_row][new_col] == -1) {
                        distance[new_row][new_col] = 1 + distance[curr_row][curr_col];
                        q.push({new_row,new_col});
                        answer = max(answer,distance[new_row][new_col]);
                    }
                }
            }
        }
        return answer;
    }
};

// The following solution doesn't work :(
class Solution2 {
    int row = 0;
    int col = 0;
    int answer = -1;
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,-1,0,1};
    int bfs(int& sr, int& sc, vector<vector<int>>& grid) {
        int distance = -1;
        vector<vector<bool>> visited(this->row,vector<bool>(this->col,false));
        queue<vector<int>> q;       // {row,col}
        q.push({sr,sc});
        visited[sr][sc] = true;
        while(!q.empty()) {
            int curr_row = q.front()[0], curr_col = q.front()[1];
            q.pop();
            for(int i=0; i<4; i++) {
                int new_row = curr_row + this->dr[i], new_col = curr_col + this->dc[i];
                if(new_row >= 0 and new_col >= 0 and new_row < this->row and new_col < this->col) {
                    if(visited[new_row][new_col] == false) {
                        q.push({new_row,new_col});
                        visited[new_row][new_col] = true;
                        if(grid[new_row][new_col] == 1) {
                            int result = abs(sr - new_row) + abs(sc - new_col);
                            distance = max(distance,result);
                        }
                    }
                }
            }
        }
        return distance;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        this->row = grid.size(), this->col = grid[0].size();
        for(int i=0; i<this->row; i++) {
            for(int j=0; j<this->col; j++) {
                if(grid[i][j] == 0) {
                    this->answer = max(this->answer,this->bfs(i,j,grid));
                }
            }
        }
        return this->answer;
    }
};