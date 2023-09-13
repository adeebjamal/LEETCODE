// Dynamic programming
// https://www.hackerrank.com/challenges/coin-change/problem?isFullScreen=true
#include<bits/stdc++.h>
using namespace std;
long long int f(int index, int amount_left, vector<int>& coins, vector<vector<long long int>>& dp) {
    if(index == coins.size()) {
        return 0;
    }
    if(amount_left == 0) {
        return 1;
    }
    if(dp[index][amount_left] != -1) {
        return dp[index][amount_left];
    }
    long long int pick = 0, not_pick = 0;
    if(coins[index] <= amount_left) {
        pick+= f(index, amount_left-coins[index], coins, dp);
    }
    not_pick+= f(index+1, amount_left, coins, dp);
    return dp[index][amount_left] = pick + not_pick;
}
int main() {
    int amount=0, number_of_coins=0;
    cin>>amount>>number_of_coins;
    vector<int> coins;
    for(int i=0; i<number_of_coins; i++) {
        int coin=0;
        cin>>coin;
        coins.push_back(coin);
    }
    vector<vector<long long int>> dp(number_of_coins,vector<long long int>(amount+1,-1));
    cout<<f(0,amount,coins,dp);
    return 0;
}