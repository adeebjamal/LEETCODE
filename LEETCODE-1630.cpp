#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int len=nums.size();
        for(int i=0; i<len-2; i++) {
            if(nums[i]-nums[i+1] != nums[i+1]-nums[i+2]) {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int len=l.size();
        for(int i=0; i<len; i++) {
            vector<int> temp(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(temp.begin(),temp.end());
            ans.push_back(check(temp));
        }
        return ans;
    }
};
int main() {
    return 0;
}