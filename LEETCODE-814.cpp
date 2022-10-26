#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    void mapper(TreeNode* root, unordered_map<int,int>& mp) {
        if(root==NULL) return;
        mp[root->val]++;
        if(mp[1]>0) return;
        mapper(root->left,mp);
        mapper(root->right,mp);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        unordered_map<int,int> mp;
        mapper(root,mp);
        if(mp[1]<1) {
            return NULL;
        }
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        return root;
    }
};
int main() {

    return 0;
}