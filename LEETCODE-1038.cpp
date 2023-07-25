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
    vector<int> nums;
    int binarySearch(int& key) {
        int start=0, end=nums.size()-1;
        while(start <= end) {
            int mid=(start+end)/2;
            if(nums[mid] == key) {
                return mid;
            }
            else if(nums[mid] > key) {
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        return -1;
    }
    void solve(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        int index=binarySearch(root->val);
        root->val=accumulate(nums.begin()+index,nums.end(),0);
        solve(root->left);
        solve(root->right);
    }
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        dfs(root);
        solve(root);
        return root;
    }
};