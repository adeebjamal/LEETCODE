#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> answer;
    void f(int index, int target, vector<int>& nums, vector<int>& subset) {
        if(index == nums.size()) {
            if(target == 0) {
                this->answer.push_back(subset);
            }
            return;
        }
        if(nums[index] <= target) {
            subset.push_back(nums[index]);
            this->f(index, target-nums[index], nums, subset);
            subset.pop_back();
        }
        this->f(index+1, target, nums, subset);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        this->f(0,target,candidates,subset);
        return this->answer;
    }
};