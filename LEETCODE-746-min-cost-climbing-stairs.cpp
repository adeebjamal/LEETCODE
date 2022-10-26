/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int n, vector<int>& cost, vector<int>& dp) {
        if(n==cost.size()-1) return cost.back();
        if(n==cost.size()) return 0;
        if(dp[n] != -1) return dp[n];
        int one_step=cost[n]+solve(n+1,cost,dp);
        int two_steps=cost[n]+solve(n+2,cost,dp);
        return dp[n]=min(one_step,two_steps);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};
int main() {
    Solution* obj;
    vector<int> cost={10,15,20};
    cout<<obj->minCostClimbingStairs(cost)<<endl;
    cost={1,100,1,1,1,100,1,1,100,1};
    cout<<obj->minCostClimbingStairs(cost)<<endl;
    return 0;
}