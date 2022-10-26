#include<bits/stdc++.h>
using namespace std;
int tribonacci(int n) {
    vector<int> nums={0,1,1};
    for(int i=3; i<=n; i++) {
        int len=nums.size();
        nums.push_back(nums[len-1] + nums[len-2] + nums[len-3]);
    }
    return nums[n];
}
int main() {
    int n=0;
    cin>>n;
    cout<<tribonacci(n)<<endl;
    return 0;
}