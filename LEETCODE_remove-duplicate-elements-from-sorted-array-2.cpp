#include<bits/stdc++.h>
using namespace std;
// this fuction calculate length of required array without modifying the actual array.
int RemoveDuplicateLen(vector<int>& nums) {
    int i=0, sum=0;
    auto it=nums.begin();
    while(it!=nums.end()) {
        int curr_count=count(nums.begin()+i, nums.end(), nums[i]);
        if(curr_count==1) {
            sum+=1;
            i+=1;
            it+=1;
        }
        else if(curr_count>=2) {
            sum+=2;
            i+=curr_count;
            it+=curr_count;
        }
    }
    return sum;
}
// this function modify the actual array O(n^2)
int RemoveDuplicate(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++) {
        int curr_count=count(nums.begin(), nums.end(), nums[i]);
        if(curr_count>2) {
            for(int j=0; j<curr_count-2; j++) {
                auto it=find(nums.begin(), nums.end(), nums[i]);
                nums.erase(it);
            }
        }
    }
    return nums.size();
}
// this function modifies thr array in optimized way
int RemoveDuplicateOptimized(vector<int>& nums) {
    int i=0;
    while(i<nums.size()) {
        int curr_count=count(nums.begin(), nums.end(), nums[i]);
        if(curr_count>2) {
            nums.erase(nums.begin()+i, nums.begin()+i+curr_count-2);
        }
        i+=2;
    }
    return nums.size();
}
int main() {
    vector<int> v={0,0,0,1,2,2,2,3,3,4,4,4,4};
    cout<<RemoveDuplicateOptimized(v)<<endl;
    for(int& i: v) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}