#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> hash;
        int sum = 2 * pow(2, 20), answer = 0, mod = 1e9 + 7;
        for(int& num: deliciousness) {
            int power = 1;
            for(int i = 0; power <= sum; i++) {
                if(hash.find(power - num) != hash.end()) {
                    answer += hash[power - num];
                    answer %= mod;
                }
                power *= 2;
            }
            hash[num]++;
        }
        return answer;
    }
};