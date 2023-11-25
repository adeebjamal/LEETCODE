#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int shortestPath(vector<vector<int>>& grid, pair<int,int> source, pair<int,int> destination) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        distance[source.first][source.second] = 0;
        q.push({0, source.first, source.second});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while(q.empty() == false) {
            int dist = q.front()[0], row = q.front()[1], col = q.front()[2];
            q.pop();
            for(int i = 0; i < 4; i++) {
                int newrow = row + dr[i], newcol = col + dc[i];
                if(newrow >= 0 and newrow < n and newcol >= 0 and newcol < m) {
                    if(grid[newrow][newcol] == 1) {
                        if(distance[newrow][newcol] > dist + 1) {
                            distance[newrow][newcol] = dist + 1;
                            q.push({dist + 1, newrow, newcol});
                        }
                    }
                }
            }
        }
        return (distance[destination.first][destination.second] == 1e9) ? -1 : distance[destination.first][destination.second];
    }
};