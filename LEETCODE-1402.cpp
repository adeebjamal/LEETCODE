#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int time, int index, vector<int>& nums, vector<vector<int>>& dp) {
        if(index>=nums.size()) {
            return 0;
        }
        if(dp[time][index] != -1) {
            return dp[time][index];
        }
        int take = nums[index]*time + solve(time+1,index+1,nums,dp);
        int skip = 0 + solve(time,index+1,nums,dp);
        return dp[time][index] = max(take,skip);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int t=satisfaction.size()+1, len=satisfaction.size();
        vector<vector<int>> dp(t,vector<int>(len,-1));
        return solve(1,0,satisfaction,dp);
    }
};
int main() {
    Solution* obj;
    vector<int> satisfaction = {-1,-8,0,5,-9};
    cout<<obj->maxSatisfaction(satisfaction)<<endl;
    satisfaction = {4,3,2};
    cout<<obj->maxSatisfaction(satisfaction)<<endl;
    satisfaction = {-1,-4,-5};
    cout<<obj->maxSatisfaction(satisfaction);
    return 0;
}