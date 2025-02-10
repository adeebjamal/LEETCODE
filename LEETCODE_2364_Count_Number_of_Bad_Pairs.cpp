#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // j - i != nums[j] - nums[i]
        // => nums[i] - i != nums[j] - j
        unsigned long long int n = nums.size();
        unordered_map<int, int> hash;
        for(int i = 0; i < n; i++) {
            hash[nums[i] - i]++;
        }
        unsigned long long int goodPairCount = 0;
        for(auto& itr: hash) {
            unsigned long long int m = itr.second;
            goodPairCount += m * (m - 1) / 2;
        }
        return n * (n - 1) / 2 - goodPairCount;
    }
};