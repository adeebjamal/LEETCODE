#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int> nums) {
        if(count(nums.begin(),nums.end(),0)>1) {
            vector<int> ans(nums.size(),0);
            return ans;
        }
        int product=1, zeros=0;
        for(int& num: nums) {
            if(num==0) {
                zeros++;
                continue;
            }
            product*= num;
        }
        if(zeros>0) {
            for(int& num: nums) {
                if(num != 0) {
                    num=0;
                }
                else if(num==0) {
                    num=product;
                }
            }
            return nums;
        }
        for(int& num: nums) {
            num=product/num;
        }
        return nums;
    }
};
int main() {
    Solution* obj;
    for(int& num: obj->productExceptSelf({1,2,3,4})) {
        cout<<num<<" ";
    }
    cout<<endl;
    for(int& num: obj->productExceptSelf({-1,1,0,-3,3})) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}