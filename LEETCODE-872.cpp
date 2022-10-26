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
    void preorder(TreeNode* root, vector<int>& leaf) {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) leaf.push_back(root->val);
        preorder(root->left,leaf);
        preorder(root->right,leaf);
    }
    vector<int> leaves(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> leaf;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len=q.size();
            for(int i=0; i<len; i++) {
                if(q.front()->left==NULL && q.front()->right==NULL) leaf.push_back(q.front()->val);
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
        }
        return leaf;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> one, two;
        preorder(root1,one);
        preorder(root2,two);
        return one==two;
    }
};
int main() {
    TreeNode* root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->left->left=new TreeNode(3);
    TreeNode* root2=new TreeNode(3);
    cout<<root1->leafSimilar(root1,root2)<<" ";
    for(int& num: root1->leaves(root1)) {
        cout<<num<<" ";
    }
    for(int& num: root2->leaves(root2)) {
        cout<<num<<" ";
    }
    return 0;
}