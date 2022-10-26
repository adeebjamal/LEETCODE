#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    void root_to_leaf(TreeNode* root, vector<int> path, vector<vector<int>>& paths) {
        if(root==NULL) return;
        path.push_back(root->val);
        if(root->left==NULL and root->right==NULL) {
            paths.push_back(path);
            return;
        }
        root_to_leaf(root->left,path,paths);
        root_to_leaf(root->right,path,paths);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<vector<int>> paths;
        root_to_leaf(root,{},paths);
        string mini="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        for(vector<int>& path: paths) {
            string current="";
            for(int i=path.size()-1; i>=0; i--) {
                current.push_back(path[i]+'a');
            }
            mini=min(mini,current);
        }
        return mini;
    }
};