#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countPairs(vector<int>& nums, int target) {
        long long result=0;
        for(int start=0, end=nums.size()-1; start<end; start++) {
            while(start<end and nums[start]+nums[end]>target) {
                end--;
            }
            result+= end-start;
        }
        return result;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return countPairs(nums,upper)-countPairs(nums,lower-1);
    }
};