#include<bits/stdc++.h>
using namespace std;
int solve(int index, int length, vector<int>& price, vector<vector<int>>& dp) {
    if(index < 0) {
        return 0;
    }
    if(dp[index][length] != -1) {
        return dp[index][length];
    }
    int dont_cut = 0 + solve(index-1, length, price, dp);
    int cut = 0;
    if(index+1 <= length) {
        cut = price[index] + solve(index, length-index-1,price, dp);
    }
    return dp[index][length] = max(cut,dont_cut);
}
int cutRod(vector<int> &price, int length) {
    int n=price.size();
    vector<vector<int>> dp(n, vector<int>(length+1,-1));
    return solve(n-1,length,price,dp);
}
int main() {
    int tc=0;
    cin>>tc;
    while(tc--) {
        int len=0;
        cin>>len;
        vector<int> price;
        for(int i=0; i<len; i++) {
            int x=0;
            cin>>x;
            price.push_back(x);
        }
        cout<<cutRod(price,len)<<endl;
    }
    return 0;
}