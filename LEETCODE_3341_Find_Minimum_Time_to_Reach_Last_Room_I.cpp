#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
class Solution {
    public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        time[0][0] = 0;
        while(pq.empty() == false) {
            int dist = pq.top()[0], row = pq.top()[1], col = pq.top()[2];
            pq.pop();
            if(row == n - 1 and col == m - 1) {
                return dist;
            }
            for(int i = 0; i < 4; i++) {
                int newRow = row + dr[i], newCol = col + dc[i];
                if(newRow >= 0 and newRow < n and newCol >= 0 and newCol < m) {
                    int newTime = max(dist, moveTime[newRow][newCol]) + 1;
                    if(newTime < time[newRow][newCol]) {
                        time[newRow][newCol] = newTime;
                        pq.push({newTime, newRow, newCol});
                    }
                }
            }
        }
        return -1;
    }
};