#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    void mapper(TreeNode* root, unordered_map<int,int>& mp) {
        if(root==NULL) return;
        mp[root->val]++;
        if(mp[1]>0) return;
        mapper(root->left,mp);
        mapper(root->right,mp);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        unordered_map<int,int> mp;
        mapper(root,mp);
        if(mp[1]<1) {
            return NULL;
        }
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        return root;
    }
};
class Solution {
public:
    void hash(TreeNode* root, int& flag) {
        if(root == NULL) {
            return;
        }
        if(root->val == 1) {
            flag++;
            return;
        }
        hash(root->left,flag);
        hash(root->right,flag);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        int flag = 0;
        hash(root,flag);
        if(flag == 0) {
            return NULL;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root;
    }
};
int main() {

    return 0;
}