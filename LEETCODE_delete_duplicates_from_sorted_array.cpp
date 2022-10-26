#include<bits/stdc++.h>
using namespace std;
int fuction(vector<int> nums) {
    set<int> myset;
    for(int i: nums) {
        myset.insert(i);
    }
    return myset.size();
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
    cout<<fuction(nums)<<endl;
    return 0;
}