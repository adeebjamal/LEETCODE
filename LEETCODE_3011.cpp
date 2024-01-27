#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool f(vector<pair<int,int>>& vec) {
        bool result = false;
        for(int i = 0; i < vec.size() - 1; i++) {
            if(vec[i].second == vec[i+1].second and vec[i].first > vec[i+1].first) {
                result = true;
                swap(vec[i], vec[i+1]);
            }
        }
        return result;
    }
    public:
    bool canSortArray(vector<int>& nums) {
        bool sorted = true;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i+1]) {
                sorted = false;
                break;
            }
        }
        if(sorted == true) {
            return true;
        }
        vector<pair<int, int>> vec;
        for(int& num: nums) {
            vec.push_back({num, __builtin_popcount(num)});
        }
        while(this->f(vec)) {

        }
        for(int i = 0; i < vec.size() - 1; i++) {
            if(vec[i].first > vec[i+1].first) {
                return false;
            }
        }
        return true;
    }
};