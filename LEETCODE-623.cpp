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
    TreeNode(int val, TreeNode* left, TreeNode* right) {
        this->val=val;
        this->left=left;
        this->right=right;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(depth--) {
            int len=q.size();
            for(int i=0; i<len; i++) {
                if(depth>1) {
                    if(q.front()->left != NULL) q.push(q.front()->left);
                    if(q.front()->right != NULL) q.push(q.front()->right);
                }
                else {
                    q.front()->left=new TreeNode(val,q.front()->left,NULL);
                    q.front()->right=new TreeNode(val,NULL,q.front()->right);
                }
                q.pop();
            }
        }
        return root;
    }
};
int main() {

    return 0;
}