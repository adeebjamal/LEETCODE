#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, unsigned long long int> hash;
        unordered_map<unsigned long long int, int> freq_map;
        priority_queue<unsigned long long int> pq;
        vector<long long> answer;
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            int number = nums[i];
            unsigned long long int old_frequency = hash[number];
            hash[number] = 0 >= hash[number] + freq[i] ? 0 : hash[number] + freq[i];
            unsigned long long int new_frequency = hash[number];

            freq_map[old_frequency]--;
            freq_map[new_frequency]++;
            pq.push(new_frequency);

            while(pq.empty() == false and freq_map[pq.top()] == 0) {
                pq.pop();
            }

            answer.push_back(pq.top());
        }

        return answer;
    }
};