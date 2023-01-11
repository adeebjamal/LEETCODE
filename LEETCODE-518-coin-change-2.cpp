#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(index==coins.size()) {
            return 0;
        }
        if(amount==0) {
            return 1;
        }
        if(dp[index][amount] != -1) {
            return dp[index][amount];
        }
        int not_take=solve(index+1,amount,coins,dp);
        int take=0;
        if(coins[index]<=amount) {
            take=solve(index,amount-coins[index],coins,dp);
        }
        return dp[index][amount]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        int len=coins.size();
        vector<vector<int>> dp(len,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};
int main() {
    Solution* obj;
    vector<int> coins={1,2,5};
    cout<<obj->change(5,coins)<<endl;
    coins={10};
    cout<<obj->change(10,coins)<<endl;
    coins={2};
    cout<<obj->change(3,coins)<<endl;
    return 0;
}