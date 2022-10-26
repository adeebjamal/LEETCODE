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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(q.size()) {
            int len=q.size();
            for(int i=0; i<len; i++) {
                if(i==len-1) {
                    ans.push_back(q.front()->val);
                }
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
        }
        return ans;
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
    for(int& num: root->rightSideView(root)) {
        cout<<num<<" ";
    }
    return 0;
}