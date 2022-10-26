#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
    void sumReplacement(TreeNode* root) {
        if(root==NULL) return;
        sumReplacement(root->left);
        sumReplacement(root->right);
        if(root->left != NULL) root->val+= root->left->val;
        if(root->right != NULL) root->val+= root->right->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root==NULL) return {};
        sumReplacement(root);
        unordered_map<int,int> mp;
        queue<TreeNode*> q;
        q.push(root);
        int maxi=INT_MIN;
        while(!q.empty()) {
            int len=q.size();
            for(int i=0; i<len; i++) {
                mp[q.front()->val]++;
                maxi=max(maxi,mp[q.front()->val]);
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
        }
        vector<int> ans;
        for(auto& it: mp) {
            if(it.second==maxi) ans.push_back(it.first);
        }
        return ans;
    }
};
int main() {
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(2);
    root->right=new TreeNode(-3);
    for(int& num: root->findFrequentTreeSum(root)) {
        cout<<num<<" ";
    }
    return 0;
}