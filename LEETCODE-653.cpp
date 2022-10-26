#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    vector<int> mp;
    void mapper(TreeNode* root) {
        if(root==NULL) return;
        mp.push_back(root->val);
        mapper(root->left);
        mapper(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        mapper(root);
        sort(mp.begin(),mp.end());
        int start=0, end=mp.size()-1;
        while(start<end) {
            if(mp[start]+mp[end]==k) {
                return true;
            }
            else if(mp[start]+mp[end]<k) {
                start++;
            }
            else {
                end--;
            }
        }
        return  false;
    }
};
int main() {

    return 0;
}