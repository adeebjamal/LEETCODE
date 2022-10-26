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
    void root_to_leaf(TreeNode* root, string path, vector<string>& paths) {
        if(root==NULL) return;
        path+= to_string(root->val);
        if(root->left == NULL and root->right == NULL) {
            paths.push_back(path);
            return;
        }
        path+= "->";
        root_to_leaf(root->left,path,paths);
        root_to_leaf(root->right,path,paths);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        root_to_leaf(root,"",paths);
        return paths;
    }
};
int main() {
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    for(string& path: root->binaryTreePaths(root)) {
        cout<<path<<endl;
    }
    return 0;
}