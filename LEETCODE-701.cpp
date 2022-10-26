#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) {
            return new TreeNode(val);
        }
        if(root->val > val) {
            root->left=insertIntoBST(root->left,val);
        }
        if(root->val < val) {
            root->right=insertIntoBST(root->right,val);
        }
        return root;
    }
};
int main() {

    return 0;
}