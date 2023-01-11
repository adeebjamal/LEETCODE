#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(index==0) {
            if(target%nums[0]==0) return target/nums[0];
            return 1e8;
        }
        if(dp[index][target] != -1) {
            return dp[index][target];
        }
        int not_take=0+solve(index-1,target,nums,dp);
        int take=INT_MAX;
        if(nums[index]<=target) {
            take=1+solve(index,target-nums[index],nums,dp);
        }
        return dp[index][target] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int len=coins.size();
        vector<vector<int>> dp(len,vector<int>(amount+1,-1));
        int answer=solve(len-1,amount,coins,dp);
        if(answer>=1e8) {
            return -1;
        }
        return answer;
    }
};
int main() {
    vector<int> coins={1,2,5};
    Solution* obj;
    cout<<obj->coinChange(coins,11)<<endl;
    coins={2};
    cout<<obj->coinChange(coins,3)<<endl;
    coins={1};
    cout<<obj->coinChange(coins,0);
    return 0;
}