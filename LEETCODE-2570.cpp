#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        for(vector<int>& row: nums1) {
            mp[row[0]]+= row[1];
        }
        for(vector<int>& row: nums2) {
            mp[row[0]]+= row[1];
        }
        nums1={};
        for(auto& itr: mp) {
            nums1.push_back({itr.first,itr.second});
        }
        return nums1;
    }
};