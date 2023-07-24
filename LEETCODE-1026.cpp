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
class Solution {
public:
    int answer = INT_MIN;
    void diff(TreeNode* root, int& rootVal) {
        if(root == NULL) {
            return;
        }
        answer = max(answer,abs(root->val - rootVal));
        diff(root->left,rootVal);
        diff(root->right,rootVal);
    }
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        diff(root,root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return answer;
    }
};