#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        for(vector<int>& row: matrix) {
            for(int& num: row) {
                nums.push_back(num);
            }
        }
        sort(nums.begin(),nums.end());
        return nums[k-1];
    }
};
int main() {
    return 0;
}