#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    int len=nums.size();
    for(int i=0; i<len-1; i++) {
        int low=i+1, high=len-1;
        while(low<high) {
            if(nums[i]+nums[low]+nums[high]==0) {
                ans.push_back({nums[i],nums[low],nums[high]});
            }
            else if(nums[i]+nums[low]+nums[high] > 0) {
                high--;
            }
            else if(nums[i]+nums[low]+nums[high] < 0) {
                low++;
            }
        }
    }
    return ans;
}
int main() {

    return 0;
}