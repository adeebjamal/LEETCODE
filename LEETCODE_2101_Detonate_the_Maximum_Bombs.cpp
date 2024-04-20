#include<bits/stdc++.h>
using namespace std;
class Solution {
    double distance(int& x1, int& y1, int& x2, int& y2) {
        long long int a1 = x1;
        long long int b1 = y1;
        long long int a2 = x2;
        long long int b2 = y2;
        return sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int len = bombs.size(), answer = 0;
        for(int i = 0; i < len; i++) {
            int count = 0;
            vector<bool> detonated(len, false);
            queue<int> q;
            q.push(i);
            detonated[i] = true;
            while(q.empty() == false) {
                int bomb_index = q.front();
                q.pop();
                vector<int> bomb = bombs[bomb_index];
                count++;
                int x1 = bomb[0], y1 = bomb[1], r1 = bomb[2];
                for(int j = 0; j < len; j++) {
                    if(j == bomb_index or detonated[j] == true) {
                        continue;
                    }
                    int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                    if(this->distance(x1, y1, x2, y2) <= r1) {
                        q.push(j);
                        detonated[j] = true;
                    }
                }
                answer = max(answer, count);
            }
        }
        return answer;
    }
};