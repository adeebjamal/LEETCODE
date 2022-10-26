#include<bits/stdc++.h>
using namespace std;
int maximumDifference(vector<int>& nums) {
    int len=nums.size(), diff=INT_MIN;
    for(int i=len-1; i>=1; i--) {
        for(int j=i-1; j>=0; j--) {
            if(nums[i]>nums[j]) {
                diff=max(diff,nums[i]-nums[j]);
            }
        }
    }
    if(diff==INT_MIN) {
        return -1;
    }
    return diff;
}
int main() {
    vector<int> nums1={7,1,5,4};
    cout<<maximumDifference(nums1)<<" ";
    vector<int> nums2={9,4,3,2};
    cout<<maximumDifference(nums2)<<" ";
    return 0;
}