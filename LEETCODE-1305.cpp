#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    vector<int> nums;
    void helper(TreeNode* root) {
        if(root==NULL) return;
        nums.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        helper(root1);
        helper(root2);
        sort(nums.begin(),nums.end());
        return nums;
    }
};
int main() {

    return 0;
}