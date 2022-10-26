/*
You are a professional robber planning to rob houses along a street. Each house has a certain
amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent 
houses have security systems connected and it will automatically contact the police if two adjacent 
houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount
of money you can rob tonight without alerting the police.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, int ind) {
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+solve(dp,nums,ind-2);
        int not_pick=0+solve(dp,nums,ind-1);
        return dp[ind]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int len=nums.size();
        vector<int> dp(len,-1);
        return solve(dp,nums,len-1);
    }
};
int main() {
    Solution* obj;
    vector<int> nums={1,2,3,1};
    cout<<obj->rob(nums)<<endl;
    nums={2,7,9,3,1};
    cout<<obj->rob(nums)<<endl;
    return 0;
}