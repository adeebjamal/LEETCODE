#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* solve(vector<int>& nums, int start, int end) {
        if(end-start <= 0) {
            return NULL;
        }
        int maxi = max_element(nums.begin()+start,nums.begin()+end+1)-nums.begin();
        TreeNode* node = new TreeNode(nums[maxi]);
        node->left = solve(nums,start,maxi-1);
        node->right = solve(nums,maxi+1,end);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) {
            return NULL;
        }
        return solve(nums,0,nums.size()-1);
    }
};