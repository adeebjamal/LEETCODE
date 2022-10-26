/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Input: n=3
Output: 3
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& dp, int n) {
        if(dp[n]!=-1) return dp[n];
        if(n==0) return 1;
        int one=solve(dp,n-1);
        int two=0;
        if(n-2>=0) two=solve(dp,n-2);
        return dp[n]=one+two;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(dp,n);
    }
};
int main() {
    Solution* obj;
    cout<<obj->climbStairs(2);
    return 0;
}