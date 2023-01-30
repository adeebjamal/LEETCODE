#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<vector<int>> subsets;
    bool check(vector<int>& subset) {
        for(int i=0; i<subset.size()-1; i++) {
            if(subset[i] > subset[i+1]) {
                return false;
            }
        }
        return true;
    }
    void generate(vector<int>& subset, int index, vector<int>& nums) {
        if(index==nums.size()) {
            if(subset.size() >= 2) {
                if(check(subset)) {
                    subsets.insert(subset);
                }
            }
            return;
        }
        generate(subset,index+1,nums);
        subset.push_back(nums[index]);
        generate(subset,index+1,nums);
        subset.pop_back();
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> empty;
        generate(empty,0,nums);
        return vector<vector<int>>(subsets.begin(),subsets.end());
    }
};
int main() {
    Solution* obj;
    vector<int> nums={4,6,7,7};
    for(vector<int>& subset: obj->findSubsequences(nums)) {
        for(int& num: subset) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    nums={4,4,3,2,1};
    for(vector<int>& subset: obj->findSubsequences(nums)) {
        for(int& num: subset) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}