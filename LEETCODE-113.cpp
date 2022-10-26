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
    void root_to_leaf(TreeNode* root, vector<int> path, vector<vector<int>>& paths, int& target) {
        if(root==NULL) return;
        path.push_back(root->val);
        if(root->left==NULL and root->right==NULL) {
            if(accumulate(path.begin(),path.end(),0)==target) {
                paths.push_back(path);
            }
            return;
        }
        root_to_leaf(root->left,path,paths,target);
        root_to_leaf(root->right,path,paths,target);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        root_to_leaf(root,{},paths,targetSum);
        return paths;
    }
};
int main() {

    return 0;
}