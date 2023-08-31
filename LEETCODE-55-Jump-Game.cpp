// https://leetcode.com/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int length = 0;
public:
    bool f(int index, vector<int>& nums, vector<int>& dp) {
        if(index == this->length - 1) {
            return true;
        }
        if(nums[index] == 0) {
            return false;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        for(int step=1; step <= nums[index]; step++) {
            if(step < this->length and this->f(index + step, nums, dp) == true) {
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        this->length = nums.size();
        vector<int> dp(this->length,-1);
        return this->f(0,nums,dp);
    }
};