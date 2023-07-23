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
    bool same(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL) {
            return true;
        }
        if(p == NULL or q == NULL) {
            return false;
        }
        if(p->val != q->val) {
            return false;
        }
        return same(p->left,q->left) and same(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len = q.size();
            for(int i=0; i<len; i++) {
                if(q.front()->val == subRoot->val) {
                    if(same(q.front(),subRoot) == true) {
                        return true;
                    }
                }
                if(q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        return false;
    }
};