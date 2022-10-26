#include<bits/stdc++.h>
using namespace std;
int remove_duplicates(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++) {
        int curr_count=count(nums.begin(), nums.end(), nums[i]);
        for(int j=1; j<curr_count; j++) {
            auto it=find(nums.begin()+i+1, nums.end(), nums[i]);
            nums.erase(it);
        }
    }
    return nums.size();
}
int main() {
    vector<int> v={0,0,0,1,1,1,2,2,3,3,3,3,4};
    cout<<remove_duplicates(v)<<endl;
    for(int& i: v) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}