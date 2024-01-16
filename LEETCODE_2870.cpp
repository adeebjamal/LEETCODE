#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> hash;
        int answer = 0;
        for(int& num: nums) {
            hash[num]++;
        }
        for(auto& itr: hash) {
            if(itr.second == 1) {
                return -1;
            }
            answer += itr.second / 3;
            if(itr.second % 3 != 0) {
                answer++;
            }
        }
        return answer;
    }
};