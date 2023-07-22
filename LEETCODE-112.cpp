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
    int target = 0;
    bool answer = false;
    void dfs(TreeNode* root, int sum) {
        if(root == NULL) {
            return;
        }
        sum+= root->val;
        if(root->left == NULL and root->right == NULL) {
            if(sum == target) {
                this->answer = true;
                return;
            }
        }
        this->dfs(root->left,sum);
        this->dfs(root->right,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        this->target = targetSum;
        this->dfs(root,0);
        return this->answer;
    }
};