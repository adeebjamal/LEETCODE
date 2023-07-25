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
    void dfs(TreeNode* root, priority_queue<int,vector<int>,greater<int>>& pq) {
        if(root == NULL) {
            return;
        }
        pq.push(root->val);
        dfs(root->left,pq);
        dfs(root->right,pq);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        dfs(root,pq);
        k--;
        while(k--) {
            pq.pop();
        }
        return pq.top();
    }
};