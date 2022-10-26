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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return -1;
        vector<vector<int>> bfs;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len=q.size();
            vector<int> level;
            for(int i=0; i<len; i++) {
                level.push_back(q.front()->val);
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
            bfs.push_back(level);
        }
        return bfs.back().front();
    }
};
int main() {
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    root->left->right->left=new TreeNode(8);
    cout<<root->findBottomLeftValue(root);
    return 0;
}