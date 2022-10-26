#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    void root_to_leaf(TreeNode* root, deque<int> path, vector<deque<int>>& paths) {
        if(root==NULL) return;
        path.push_back(root->val);
        if(root->left==NULL and root->right==NULL) {
            paths.push_back(path);
            return;
        }
        root_to_leaf(root->left,path,paths);
        root_to_leaf(root->right,path,paths);
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<deque<int>> paths;
        deque<int> path;
        root_to_leaf(root,path,paths);
        int ans=0;
        for(deque<int>& path: paths) {
            int sum= accumulate(path.begin(),path.end(),0);
            while(!path.empty()) {
                if(sum==targetSum) {
                    ans++;
                    break;
                }
                else {
                    sum-=path[0];
                    path.pop_front();
                }
            }
        }
        return ans;
    }
};
int main() {

    return 0;
}