/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned
into two subsets such that the sum of elements in both subsets is equal.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(target==0) return true;
        if(ind==0) return nums[ind]==target;
        if(dp[ind][target] != -1) return dp[ind][target];
        bool not_take=solve(ind-1,target,nums,dp);
        bool take=false;
        if(nums[ind]<=target) take=solve(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target] = take or not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        sum/=2;   // half the sum
        int len=nums.size();
        vector<vector<int>> dp(len,vector<int>(sum+1,-1));
        return solve(len-1,sum,nums,dp);
    }
};
int main() {
    Solution* obj;
    vector<int> nums={1,5,11,5};
    cout<<obj->canPartition(nums)<<endl;
    nums={1,2,3,5};
    cout<<obj->canPartition(nums);
    return 0;
}