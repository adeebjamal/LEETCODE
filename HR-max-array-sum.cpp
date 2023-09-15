#include <bits/stdc++.h>
using namespace std;
int f(int index, vector<int>& arr, vector<int>& dp) {
    if(index >= arr.size()) {
        return 0;
    }
    if(dp[index] != -1) {
        return dp[index];
    }
    int pick = 0, not_pick = 0;
    pick = arr[index] + f(index+2, arr, dp);
    not_pick = 0 + f(index+1, arr, dp);
    return dp[index] = max(pick, not_pick);
}
int main() {
    int n=0;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++) {
        int x=0;
        cin>>x;
        nums.push_back(x);
    }
    vector<int> dp(n,-1);
    cout<<f(0,nums,dp);
    return 0;
}