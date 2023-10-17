#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=0; i<nums.size(); ) {
            int current_count = 1, start = i;
            for(int j=start; j<nums.size()-1; j++) {
                if(nums[j] == nums[j+1]) {
                    current_count++;
                }
                else {
                    break;
                }
            }
            nums.erase(nums.begin()+start,nums.begin()+start+current_count-1);
            i = start + 1;
        }
        return nums.size();
    }
};