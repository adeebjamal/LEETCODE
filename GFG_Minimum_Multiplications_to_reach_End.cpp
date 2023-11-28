#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) {
            return 0;
        }
        queue<pair<int,int>> q;
        int mod = 100000;
        vector<int> distance(mod, 1e9);
        q.push({start, 0});
        distance[start] = 0;
        while(q.empty() == false) {
            int node = q.front().first, steps = q.front().second;
            q.pop();
            for(int& num: arr) {
                int neighbour = (num * node) % mod;
                if(neighbour == end) {
                    return steps + 1;
                }
                if(steps + 1 < distance[neighbour]) {
                    distance[neighbour] = steps + 1;
                    q.push({neighbour, steps + 1});
                }
            }
        }
        return -1;
    }
};