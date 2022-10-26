#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    unordered_map<string,vector<TreeNode*>> mp;
    string helper(TreeNode* root) {
        if(root==NULL) return "";
        string l=helper(root->left), r=helper(root->right);
        string str=to_string(root->val) + "." + l + "." + r;
        mp[str].push_back(root);
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        vector<TreeNode*> ans;
        for(auto& it: mp) {
            if(it.second.size()>1) {
                ans.push_back(it.second[0]);
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}