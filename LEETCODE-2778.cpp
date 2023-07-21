#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int answer=0, len=nums.size();
        for(int i=0; i<len; i++) {
            if(len%(i+1)==0) {
                answer+= nums[i]*nums[i];
            }
        }
        return answer;
    }
};