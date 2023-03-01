#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end) {
        int len1=mid-start+1, len2=end-mid;
        vector<int> temp1, temp2;
        for(int i=0; i<len1; i++) {
            temp1.push_back(nums[start+i]);
        }
        for(int i=0; i<len2; i++) {
            temp2.push_back(nums[mid+1+i]);
        }
        int index1=0, index2=0, index=start;
        while(index1<len1 and index2<len2) {
            if(temp1[index1] < temp2[index2]) {
                nums[index++] = temp1[index1++];
            }
            else {
                nums[index++] = temp2[index2++];
            }
        }
        while(index1<len1) {
            nums[index++] = temp1[index1++];
        }
        while(index2<len2) {
            nums[index++] = temp2[index2++];
        }
    }
    void merge_sort(vector<int>& nums, int start, int end) {
        if(start>=end) {
            return;
        }
        int mid=start+(end-start)/2;
        merge_sort(nums,start,mid);
        merge_sort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};