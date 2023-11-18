#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        for(vector<int>& road: roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({degree[i], i});
        }
        int count = n;
        vector<int> ranks(n,0);
        while(!pq.empty()) {
            ranks[pq.top().second] = count--;
            pq.pop();
        }
        unsigned long long int answer = 0;
        for(vector<int>& road: roads) {
            answer += (ranks[road[0]] + ranks[road[1]]);
        }
        return answer;
    }
};
int main() {
    Solution* obj = new Solution();
    vector<vector<int>> roads = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    cout<<obj->maximumImportance(5, roads)<<endl;
    return 0;
}