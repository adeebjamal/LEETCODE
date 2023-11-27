#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        distance[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while(pq.empty() == false) {
            int current_effort = pq.top().first, row = pq.top().second.first, col = pq.top().second.second;
            if(row == n-1 and col == m-1) {
                return current_effort;
            }
            pq.pop();
            for(int i = 0; i < 4; i++) {
                int newrow = row + dr[i], newcol = col + dc[i];
                if(newrow >= 0 and newrow < n and newcol >= 0 and newcol < m) {
                    int effort = abs(heights[row][col] - heights[newrow][newcol]);
                    effort = max(effort, current_effort);
                    if(effort < distance[newrow][newcol]) {
                        distance[newrow][newcol] = effort;
                        pq.push({distance[newrow][newcol], {newrow, newcol}});
                    }
                }
            }
        }
        return distance.back().back();
    }
};