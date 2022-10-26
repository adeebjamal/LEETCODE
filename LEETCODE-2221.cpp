#include<bits/stdc++.h>
using namespace std;
int triangularSum(vector<int>& nums) {
    while(nums.size()>1) {
        int len=nums.size();
        vector<int> new_nums;
        for(int i=0; i<len-1; i++) {
            int res=(nums[i]+nums[i+1])%10;
            new_nums.push_back(res);
        }
        nums=new_nums;
    }
    return nums[0];
}
int triangularSum2(vector<int>& nums) {
    int len=nums.size();
    while(len>1) {
        for(int i=0; i<len-1; i++) {
            nums[i]=(nums[i]+nums[i+1])%10;
        }
        len--;
    }
    return nums[0];
}
int main() {
    vector<int> nums;
    int n=0;
    cin>>n;
    for(int i=0; i<n; i++) {
        int x=0;
        cin>>x;
        nums.push_back(x);
    }
    cout<<triangularSum(nums)<<endl;
    return 0;
}