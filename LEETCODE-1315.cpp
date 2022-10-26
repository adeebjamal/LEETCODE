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
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int sum=0;
        if(root->val%2==0) {
            if(root->left && root->left->left) {
                sum+= root->left->left->val;
            }
            if(root->left && root->left->right) {
                sum+= root->left->right->val;
            }
            if(root->right && root->right->left) {
                sum+= root->right->left->val;
            }
            if(root->right && root->right->right) {
                sum+= root->right->right->val;
            }
        }
        sum+= sumEvenGrandparent(root->left);
        sum+= sumEvenGrandparent(root->right);
        return sum;
    }
};
int main() {

    return 0;
}