#include<bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class Solution {
    public:
    void sumReplace(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        sumReplace(root->left);
        sumReplace(root->right);
        if(root->left != NULL) {
            root->val+= root->left->val;
        }
        if(root->right != NULL) {
            root->val+= root->right->val;
        }
    }
    void bfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len = q.size();
            for(int i=0; i<len; i++) {
                cout<<q.front()->val<<" ";
                if(q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            cout<<endl;
        }
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution* obj = new Solution();
    cout<<endl;
    obj->bfs(root);
    obj->sumReplace(root);
    cout<<endl;
    obj->bfs(root);
    return 0;
}