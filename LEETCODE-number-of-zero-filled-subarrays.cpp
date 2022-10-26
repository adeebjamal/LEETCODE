#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int len=nums.size();
        if(len==0) return 0LL;
        nums.push_back(-1);
        vector<vector<int>> arr;
        vector<int> temp;
        for(int i=0; i<len+1; i++) {
            if(nums[i]==0) {
                temp.push_back(0);
            }
            else if(temp.size()>0 and nums[i] != 0) {
                arr.push_back(temp);
                temp={};
            }
        }
        long long int ans=0;
        for(vector<int>& vec: arr) {
            long long int n=vec.size();
            ans+= n*(n+1)/2;
        }
        return ans;
    }
};
int main() {
    Solution ob;
    vector<int> v1={1,3,0,0,2,0,0,4}, v2={0,0,0,2,0,0}, v3={2,10,2019};
    cout<<ob.zeroFilledSubarray(v1)<<endl;
    cout<<ob.zeroFilledSubarray(v2)<<endl;
    cout<<ob.zeroFilledSubarray(v3)<<endl;
    return 0;
}