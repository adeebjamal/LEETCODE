// https://leetcode.com/problems/number-of-enclaves/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if(grid[i][j] == 1) {
                        q.push({i,j});
                        visited[i][j] = true;
                    }
                }
            }
        }
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,-1,0,+1};
        while(!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = row + drow[i], ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if(visited[nrow][ncol] == false && grid[nrow][ncol] == 1) {
                        q.push({nrow,ncol});
                        visited[nrow][ncol] = true;
                    }
                }
            }
        }
        int answer = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 and visited[i][j] == false) {
                    answer++;
                }
            }
        }
        return answer;
    }
};
int main() {
    Solution* obj = new Solution();
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout<<obj->numEnclaves(grid)<<endl;
    return 0;
}