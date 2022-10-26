#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        else if(root->val==val) return root;
        TreeNode* l=searchBST(root->left,val);
        if(l != NULL) return l;
        TreeNode* r=searchBST(root->right,val);
        if(r != NULL) return r;
        return NULL;
    }
};
int main() {

    return 0;
}