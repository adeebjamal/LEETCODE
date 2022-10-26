#include<bits/stdc++.h>
using namespace std;
int minimumDeletions(vector<int> nums) {
    int maxi= max_element(nums.begin(),nums.end()) - nums.begin();
    int mini= min_element(nums.begin(),nums.end()) - nums.begin();
    int len= nums.size(), left= min(mini,maxi), right= max(mini,maxi);
    return min(min(right+1, len-left), left+1+len-right);
}
int main() {
    cout<<minimumDeletions({2,10,7,5,4,1,8,6})<<endl;
    cout<<minimumDeletions({0,-4,19,1,8,-2,-3,5})<<endl;
    cout<<minimumDeletions({101})<<endl;
    return 0;
}