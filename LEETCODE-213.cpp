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
        return dp[n]=max(rob,not_rob);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) {
            return nums[0];
        }
        else if(nums.size()==0) {
            return 0;
        }
        else if(nums.size()==2) {
            return max(nums[0],nums[1]);
        }
        vector<int> nums1(nums.begin()+1,nums.end());
        vector<int> nums2(nums.begin(),nums.end()-1);
        int n=nums1.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(solve(n-1,nums1,dp1),solve(n-1,nums2,dp2));
    }
};
int main() {
    Solution* obj;
    vector<int> nums={2,3,2};
    cout<<obj->rob(nums)<<endl;
    nums={1,2,3,1};
    cout<<obj->rob(nums)<<endl;
    nums={1,2,3};
    cout<<obj->rob(nums)<<endl;
    return 0;
}