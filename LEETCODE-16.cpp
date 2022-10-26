#include<bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int> nums, int target) {
    sort(nums.begin(),nums.end());
    int gap=INT_MAX, len=nums.size();
    vector<int> ans;
    for(int i=0; i<len-1; i++) {
        int low=i+1, high=len-1;
        while(low<high) {
            int sum=nums[i]+nums[low]+nums[high];
            if(abs(target-sum)<gap) {
                gap=abs(target-sum);
                ans={nums[i],nums[low],nums[high]};
            }
            if(sum==target) {
                low++;
                high--;
            }
            else if(sum<target) {
                low++;
            }
            else if(sum>target) {
                high--;
            }
        }
    }
    return accumulate(ans.begin(),ans.end(),0);
}
int main() {
    cout<<threeSumClosest({-1,2,1,-4},1);
    return 0;
}