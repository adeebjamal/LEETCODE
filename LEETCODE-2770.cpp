#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int index, int& target, vector<int>& nums, vector<int>& dp) {
        if(index == nums.size()-1) {
            return 0;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        int answer = INT_MIN;
        for(int i=index+1; i<nums.size(); i++) {
            if(abs(nums[i]-nums[index]) <= target) {
                answer = max(answer,1+solve(i,target,nums,dp));
            }
        }
        return dp[index] = answer;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> dp(len,-1);
        int answer = solve(0,target,nums,dp);
        return answer > 0 ? answer : -1;
    }
};