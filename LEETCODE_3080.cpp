#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int len = nums.size();
        unsigned long long int sum = 0;
        for(int index = 0; index < len; index++) {
            pq.push({nums[index], index});
            sum += nums[index];
        }
        vector<bool> visited(len, false);
        vector<long long> answer;
        for(vector<int>& query : queries) {
            int index = query[0], k = query[1];
            if(visited[index] == false) {
                sum -= nums[index];
                visited[index] = true;
            }
            while(pq.empty() == false and k) {
                if(pq.size() > 0 and visited[pq.top().second] == true) {
                    pq.pop();
                    continue;
                }
                sum -= nums[pq.top().second];
                visited[pq.top().second] = true;
                pq.pop();
                k--;
            }
            answer.push_back(sum);
        }
        return answer;
    }
};