#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    int sum=0;
    void root_to_leaf(TreeNode* root, string num) {
        if(root==NULL) return;
        num.push_back(root->val + '0');
        if(root->left == NULL && root->right == NULL) {
            sum+= stoi(num);
            return;
        }
        root_to_leaf(root->left,num);
        root_to_leaf(root->right,num);
    }
    int sumNumbers(TreeNode* root) {
        root_to_leaf(root,"");
        return sum;
    }
};