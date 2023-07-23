#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        this->val=data;
        this->left=NULL;
        this->right=NULL;
    }
};
class FindElements2 {
public:
    TreeNode* root = NULL;
    unordered_map<int,int> mp;
    void solve(TreeNode* root, int current, bool left) {
        if(root == NULL) {
            return;
        }
        if(left == true) {
            root->val = 2 * current + 1;
        }
        else if(left == false) {
            root->val = 2 * current + 2;
        }
        mp[root->val]++;
        solve(root->left, root->val, true);
        solve(root->right, root->val, false);
    }
    FindElements2(TreeNode* root) {
        root->val = 0;
        this->root = root;
        mp[0]++;
        solve(root->left,root->val,true);
        solve(root->right,root->val,false);
    }
    
    bool find(int target) {
        return mp[target] > 0;
    }
};
class FindElements {
public:
    TreeNode* node;
    unordered_map<int,int> mp;
    void helper(TreeNode* root) {
        if(root==NULL) {
            return;
        }
        if(root->left != NULL) root->left->val = 2*root->val + 1;
        if(root->right != NULL) root->right->val = 2*root->val + 2;
        helper(root->left);
        helper(root->right);
    }
    void mapper(TreeNode* root) {
        if(root==NULL) return;
        mp[root->val]++;
        mapper(root->left);
        mapper(root->right);
    }
    FindElements(TreeNode* root) {
        this->node=root;
        this->node->val=0;
        helper(this->node);
        mapper(this->node);
    }
    bool find(int target) {
        return mp[target]>0;
    }
};
int main() {

    return 0;
}