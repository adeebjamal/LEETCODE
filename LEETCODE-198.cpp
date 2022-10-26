#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int n, vector<int>& nums, vector<int>& dp) {
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int rob=nums[n]+solve(n-2,nums,dp);
        int not_rob=0+solve(n-1,nums,dp);
        int res=max(rob,not_rob);
        return dp[n]=res;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);
    }
    int rob_tabulation(vector<int>& nums) {
        vector<int> dp={nums[0]};
        int n=nums.size();
        for(int i=1; i<n; i++) {
            int rob=INT_MIN, not_rob=INT_MIN;
            rob=nums[i]; if(i-2>=0) rob+=dp[i-2];
            not_rob=0+dp[i-1];
            dp.push_back(max(rob,not_rob));
        }
        return dp[n-1];
    }
};
int main() {
    Solution* obj;
    vector<int> nums={1,2,3,1};
    cout<<obj->rob(nums)<<endl;
    cout<<obj->rob_tabulation(nums)<<endl;
    nums={2,7,9,3,1};
    cout<<obj->rob(nums)<<endl;
    cout<<obj->rob_tabulation(nums)<<endl;
    return 0;
}