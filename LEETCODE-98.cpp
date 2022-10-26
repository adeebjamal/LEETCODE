#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    vector<int> tree;
    void inorder(TreeNode* root) {
        if(root==NULL) return;
        inorder(root->left);
        tree.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        int len=tree.size();
        for(int i=0; i<len-1; i++) {
            if(tree[i]>=tree[i+1]) {
                return false;
            }
        }
        return true;
    }
};
int main() {

    return 0;
}