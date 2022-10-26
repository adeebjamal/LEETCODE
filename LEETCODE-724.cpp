#include<bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int>& nums) {
    int right=accumulate(nums.begin(),nums.end(),0), left=0, len=nums.size();
    for(int i=0; i<len; i++) {
        right-= nums[i];
        if(right==left) {
            return i;
        }
        left+= nums[i];
    }
    return -1;
}
int main() {

    return 0;
}