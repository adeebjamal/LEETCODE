#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        vector<int> prefix_sum;
        int sum = 0;
        for(int& bit : possible) {
            sum += (bit == 1 ? 1 : -1);
            prefix_sum.push_back(sum);
        }
        for(int i = 0; i < prefix_sum.size(); i++) {
            int left_sum = prefix_sum[i], right_sum = prefix_sum.back() - prefix_sum[i];
            if(left_sum > right_sum) {
                return i + 1 != possible.size() ? i + 1 : -1;
            }
        }
        return -1;
    }
};