#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int& number: arr) {
            mp[number]++;
        }
        priority_queue<int> pq;
        for(auto& it: mp) {
            pq.push(it.second);
        }
        int len=arr.size();
        int curr_len=0, ans=0;
        while(curr_len <= len/2) {
            curr_len+= pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};