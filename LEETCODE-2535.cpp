#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int element_sum=0, digit_sum=0;
        for(int& num: nums) {
            element_sum+= num;
            int temp=num;
            while(temp) {
                digit_sum+= temp%10;
                temp/=10;
            }
        }
        return abs(element_sum-digit_sum);
    }
};