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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->left != NULL) {
            root->left = removeLeafNodes(root->left,target);
        }
        if(root->right != NULL) {
            root->right = removeLeafNodes(root->right,target);
        }
        if(root->left == NULL and root->right == NULL and root->val == target) {
            root = NULL;
        }
        return root;
    }
};