#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse_number(int num) {
        int result=0;
        while(num) {
            result = result*10 + num%10;
            num/=10;
        }
        return result;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> hash;
        for(int& num: nums) {
            hash.insert(num);
            hash.insert(reverse_number(num));
        }
        return hash.size();
    }
};