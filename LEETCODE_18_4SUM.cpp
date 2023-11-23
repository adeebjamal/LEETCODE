#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> solve(int& first, int& target, vector<int>& nums) {
        set<vector<int>> result;
        int len = nums.size();
        for(int next = first+1; next < len-2; next++) {
            int start = next+1, end = len-1;
            while(start < end) {
                if(nums[first]*1LL + nums[next]*1LL + nums[start]*1LL + nums[end]*1LL == target*1LL) {
                    result.insert({nums[first], nums[next], nums[start], nums[end]});
                    start++;
                    end--;
                }
                else if(nums[first]*1LL + nums[next]*1LL + nums[start]*1LL + nums[end]*1LL < target*1LL) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> answer;
        int len = nums.size();
        for(int i = 0 ; i < len-3; i++) {
            vector<vector<int>> result = this->solve(i, target, nums);
            for(vector<int>& temp: result) {
                answer.insert(temp);
            }
        }
        return vector<vector<int>>(answer.begin(), answer.end());
    }
};