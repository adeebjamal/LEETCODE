#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    set<int> mp;
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        this->mp.insert(root->val);
        this->dfs(root->left);
        this->dfs(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        this->dfs(root);
        if(this->mp.size() < 2) {
            return -1;
        }
        return *(++this->mp.begin());
    }
};