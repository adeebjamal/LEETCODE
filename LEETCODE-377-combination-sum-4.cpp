#include<bits/stdc++.h>
using namespace std;
class Solution {
    int f(int target, vector<int>& nums, vector<int>& dp) {
        if(target < 0) {
            return 0;
        }
        if(target == 0) {
            return 1;
        }
        if(dp[target] != -1) {
            return dp[target];
        }
        int answer = 0;
        for(int idx=0; idx < nums.size(); idx++) {
            answer+= this->f(target - nums[idx], nums, dp);
        }
        return dp[target] = answer;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return this->f(target, nums, dp);
    }
};