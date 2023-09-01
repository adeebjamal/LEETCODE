#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        vector<int> arr;
        for(int& num: nums) {
            if(mp[num] == false) {
                arr.push_back(num);
                mp[num] = true;
            }
        }
        sort(arr.begin(),arr.end());
        arr.push_back(1e9 + 7);
        int answer = 0, current_count = 1, length = arr.size();
        for(int i=0; i<length-1; i++) {
            long long int diff = arr[i+1] - arr[i];
            if(diff == 1) {
                current_count++;
            }
            else {
                answer = max(answer,current_count);
                current_count = 1;
            }
        }
        return answer;
    }
};