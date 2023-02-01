#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int num, vector<int>& dp) {
        if(num==2) {
            return 1;
        }
        else if(num<=1) {
            return num;
        }
        else if(dp[num] != -1) {
            return dp[num];
        }
        return dp[num] = solve(num-1,dp) + solve(num-2,dp) + solve(num-3,dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
int main() {
    Solution* obj;
    cout<<obj->tribonacci(4)<<endl;
    cout<<obj->tribonacci(25)<<endl;
    return 0;
}