#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(jug1Capacity + jug2Capacity == targetCapacity) {
            return true;
        }
        if(jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }
        int max_volume = jug1Capacity + jug2Capacity;
        queue<int> q;
        vector<bool> visited(max_volume + 1, false);
        q.push(0);
        visited[0] = true;
        vector<int> dv = {jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity};
        while(!q.empty()) {
            int current_volume = q.front();
            if(current_volume == targetCapacity) {
                return true;
            }
            q.pop();
            for(int i=0; i<4; i++) {
                int new_volume = current_volume + dv[i];
                if(new_volume >= 0 and new_volume <= max_volume and visited[new_volume] == false) {
                    q.push(new_volume);
                    visited[new_volume] = true;
                }
            }
        }
        return false;
    }
};