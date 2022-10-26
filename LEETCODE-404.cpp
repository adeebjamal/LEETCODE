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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int sum=0;
        if(root->left != NULL) {
            if(root->left->left==NULL && root->left->right==NULL) {
                sum+= root->left->val;
            }
        }
        sum+= sumOfLeftLeaves(root->left);
        sum+= sumOfLeftLeaves(root->right);
        return sum;
    }
};
int main() {
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<root->sumOfLeftLeaves(root);
    return 0;
}