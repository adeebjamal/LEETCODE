/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of
some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int num, vector<int>& dp) {
        if(num==0) {
            return 0;
        }
        if(dp[num] != -1) {
            return dp[num];
        }
        int ans=INT_MAX;
        for(int i=1; i*i<=num; i++) {
            ans=min(ans,1+solve(num-i*i,dp));
        }
        return dp[num]=ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
int main() {
    Solution* obj;
    cout<<obj->numSquares(12)<<endl;
    cout<<obj->numSquares(13)<<endl;
    return 0;
}