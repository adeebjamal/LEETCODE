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
    vector<int> inorder;
    void inorderTraversal(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        int mini = INT_MAX;
        for(int index=0; index<inorder.size()-1; index++) {
            mini = min(mini,inorder[index+1]-inorder[index]);
        }
        return mini;
    }
};
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(6);
    Solution* obj;
    cout<<obj->minDiffInBST(root);
    return 0;
}