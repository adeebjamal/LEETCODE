#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    void sumReplace(TreeNode* root) {
        if(root==NULL) return;
        sumReplace(root->left);
        sumReplace(root->right);
        if(root->left != NULL) root->val+= root->left->val;
        if(root->right != NULL) root->val+= root->right->val;
    }
    int value(TreeNode* root) {
        if(root==NULL) return 0;
        return root->val;
    }
    int sum(TreeNode* root) {
        if(root==NULL) return 0;
        return sum(root->left)+sum(root->right)+root->val;
    }
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        sumReplace(root);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len=q.size();
            for(int i=0; i<len; i++) {
                q.front()->val=abs(value(q.front()->left)-value(q.front()->right));
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
        }
        return sum(root);
    }
};
int main() {

    return 0;
}