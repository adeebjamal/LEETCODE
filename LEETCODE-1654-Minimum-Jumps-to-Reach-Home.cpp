#include<bits/stdc++.h>
using namespace std;
class Solution {
    int f(int idx, int& a, int& b, int& x, unordered_set<int>& mp, bool back_flag, int dp[6001][2]) {
        if(idx == x) {
            return 0;
        }
        if(idx < 0 or idx > 6000 or mp.find(idx) != mp.end()) {
            return 1e9;
        }
        if(dp[idx][back_flag] != -1) {
            return dp[idx][back_flag];
        }
        dp[idx][back_flag] = 1 + this->f(idx+a,a,b,x,mp,true,dp);
        if(back_flag) {
            dp[idx][back_flag] = min(dp[idx][back_flag], 1 + this->f(idx-b,a,b,x,mp,false,dp));
        }
        return dp[idx][back_flag];
    }
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> mp;
        for(int& position: forbidden) {
            mp.insert(position);
        }
        int dp[6001][2];
        memset(dp,-1,sizeof dp);
        int answer = this->f(0,a,b,x,mp,true,dp);
        return (answer >= 1e9) ? -1 : answer;
    }
};