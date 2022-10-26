/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence,
such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& dp, int n) {
        if(dp[n]!=-1) return dp[n];
        if(n<=1) return n;
        return dp[n]=solve(dp,n-1) + solve(dp,n-2);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solve(dp,n);
    }
};
int main() {
    Solution* obj;
    cout<<obj->fib(5);
    return 0;
}