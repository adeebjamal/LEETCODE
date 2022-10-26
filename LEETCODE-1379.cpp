#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* right;
    TreeNode* left;
    bool same(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val != q->val) return false;
        return same(p->left,q->left) && same(p->right,q->right);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(cloned);
        while(!q.empty()) {
            int len=q.size();
            for(int i=0; i<len; i++) {
                if(q.front()->val == target->val) {
                    if(same(q.front(),target)) {
                        return q.front();
                    }
                }
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
        }
        return NULL;
    }
};
int main() {

    return 0;
}