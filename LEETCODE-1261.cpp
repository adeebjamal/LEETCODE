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