#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    int maxi=INT_MIN;
    void difference(TreeNode* root, int& actual, int& diff) {
        if(root==NULL) return;
        diff=max(diff, abs(actual - root->val));
        difference(root->left,actual,diff);
        difference(root->right,actual,diff);
    }
    void preorder(TreeNode* root) {
        if(root==NULL) return;
        int actual=root->val, diff=INT_MIN;
        difference(root,actual,diff);
        maxi=max(maxi,diff);
        preorder(root->left);
        preorder(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        preorder(root);
        return maxi;
    }
};