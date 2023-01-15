#include<bits/stdc++.h>
using namespace std;
int solve(int index, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
    if(index<0) {
        return 0;
    }
    if(dp[index][W] != -1) {
        return dp[index][W];
    }
    int not_take=solve(index-1,W,val,wt,dp);
    int take=0;
    if(wt[index] <= W) {
        take=val[index] + solve(index,W-wt[index],val,wt,dp);
    }
    return dp[index][W] = max(take,not_take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<vector<int>> dp(n, vector<int>(w+1,-1));
    return solve(n-1,w,profit,weight,dp);
}
int main() {
    int tc=0;
    cin>>tc;
    while(tc--) {
        int len=0, W=0;
        cin>>len>>W;
        vector<int> val, wt;
        for(int i=0; i<len; i++) {
            int x=0;
            cin>>x;
            val.push_back(x);
        }
        for(int i=0; i<len; i++) {
            int x=0;
            cin>>x;
            wt.push_back(x);
        }
        cout<<unboundedKnapsack(len,W,val,wt)<<endl;
    }
    return 0;
}