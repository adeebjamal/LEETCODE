#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int len=nums.size(), sum=0;
        for(int& num: nums) {
            if(num%2==0) {
                sum+= num;
            }
        }
        vector<int> ans;
        for(vector<int>& query: queries) {
            int val=query[0], index=query[1];
            if(nums[index]%2==0) {
                sum-= nums[index];
            }
            nums[index]+= val;
            if(nums[index]%2==0) {
                sum+= nums[index];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
int main() {
    return 0;
}