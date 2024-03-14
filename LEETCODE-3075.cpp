#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        vector<int> nums(happiness);
        sort(nums.begin(), nums.end());
        unsigned long long int answer = 0;
        int index = nums.size() - 1, counter = 0;

        while(index >= 0) {
            if(nums[index] - counter >= 0) {
                answer += (nums[index--] - counter++);
            }
            else {
                break;
            }
            if(counter == k) {
                break;
            }
        }

        return answer;
    }
};