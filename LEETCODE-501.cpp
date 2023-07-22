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
    int maxi = INT_MIN;
    unordered_map<int,int> mp;
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        mp[root->val]++;
        maxi = max(maxi,mp[root->val]);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        vector<int> answer;
        for(auto& itr: mp) {
            if(itr.second == maxi) {
                answer.push_back(itr.first);
            }
        }
        return answer;
    }
};