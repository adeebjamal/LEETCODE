#include<bits/stdc++.h>
using namespace std;
int waysToSplitArray(vector<int>& nums) {
    int right=accumulate(nums.begin(),nums.end(),0),left=0,ans=0,len=nums.size();
    for(int i=0; i<len; i++) {
        if(left>=right) {
            ans++;
        }
        left+= nums[i];
        right-= nums[i];
    }
    return ans;
}
int main() {

    return 0;
}