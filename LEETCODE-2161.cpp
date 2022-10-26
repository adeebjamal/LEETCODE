#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, more;
        for(int& num: nums) {
            if(num<pivot) less.push_back(num);
            else if(num==pivot) equal.push_back(num);
            else more.push_back(num);
        }
        nums={};
        for(int& num: less) nums.push_back(num);
        for(int& num: equal) nums.push_back(num);
        for(int& num: more) nums.push_back(num);
        return nums;
    }
};