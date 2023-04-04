#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int& num: nums) {
            mp[num]++;
        }
        vector<vector<int>> answer;
        while(true) {
            vector<int> row;
            bool flag = true;
            for(auto& itr: mp) {
                if(itr.second >= 1) {
                    row.push_back(itr.first);
                    itr.second--;
                    flag = false;
                }
            }
            if(flag) {
                break;
            }
            answer.push_back(row);
        }
        return answer;
    }
};
int main() {
    Solution* obj;
    vector<int> nums = {1,3,4,1,2,3,1};
    for(vector<int>& row: obj->findMatrix(nums)) {
        for(int& num: row) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    nums = {1,2,3,4};
    for(vector<int>& row: obj->findMatrix(nums)) {
        for(int& num: row) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}