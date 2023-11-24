#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> answer;
        for(auto& itr: mp) {
            for(int i = itr.second.size()-1; i >= 0; i--) {
                answer.push_back(itr.second[i]);
            }
        }
        return answer;
    }
};