#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool arrange(vector<int>& nums, int& len) {
        bool ans=true;
        for(int i=1; i<len-1; i++) {
            if((nums[i-1]*1.0+nums[i+1]*1.0)/2 == nums[i]) {
                swap(nums[i],nums[i+1]);
                ans=false;
            }
        }
        return ans;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        while(arrange(nums,len)==false) {
            // execute
        }
        return nums;
    }
};
int main() {

    return 0;
}