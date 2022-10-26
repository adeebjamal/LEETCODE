#include<bits/stdc++.h>
using namespace std;
int RemoveElement(vector<int> &nums, int val) {
    vector<int> temp;
    int i=nums.size()-1;
    while(i>-1) {
        if(nums[i]==val) {
            nums.erase(nums.begin()+i);
        }
        i--;
    }
    return nums.size();
}
int main() {
    vector<int> nums;
    for(int i=0; i<5; i++) {
        int x=0;
        cin>>x;
        nums.push_back(x);
    }
    int val=0;
    cin>>val;
    cout<<RemoveElement(nums, val)<<endl;
    for(int i: nums) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}