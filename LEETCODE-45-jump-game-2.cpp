#include<bits/stdc++.h>
using namespace std;
class Solution {
    int length = 0;
public:
    int solve(int index ,vector<int>& arr, vector<int>& dp) {
        if(index == this->length - 1) {
            return 0;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        int answer = this->length;
        for(int step=1; step<=arr[index]; step++) {
            if(index + step < this->length) {
                int current_count = 1 + this->solve(index + step, arr, dp);
                answer = min(answer,current_count);
            }
        }
        return dp[index] = answer;
    }
    int jump(vector<int>& nums) {
        this->length = nums.size();
        vector<int> dp(this->length,-1);
        return this->solve(0,nums,dp);
    }
};