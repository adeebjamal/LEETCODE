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
    int answer = 0;
    int sum(TreeNode* root, int& count) {
        if(root == NULL) {
            return 0;
        }
        count++;
        return root->val + sum(root->left,count) + sum(root->right,count);
    }
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        int curr_count = 0;
        int curr_sum = sum(root,curr_count);
        if(root->val == curr_sum / curr_count) {
            answer++;
        }
        dfs(root->left);
        dfs(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return answer;
    }
};