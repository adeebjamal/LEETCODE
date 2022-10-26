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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()) {
            int len=q.size();
            level++;
            for(int i=0; i<len; i++) {
                if(q.front()->left == NULL && q.front()->right == NULL) return level;
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
        }
        return level;
    }
};
int main() {
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(1);
    root->right=new TreeNode(1);
    root->right->left=new TreeNode(1);
    root->right->right=new TreeNode(1);
    cout<<root->minDepth(root);
    return 0;
}