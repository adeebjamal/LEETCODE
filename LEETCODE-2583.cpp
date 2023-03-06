#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL) return -1;
        priority_queue<long long int> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int len = q.size();
            long long int sum = 0;
            for(int i=0; i<len; i++) {
                sum+= q.front()->val*1LL;
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
            pq.push(sum);
        }
        if(pq.size() < k) return -1;
        k--;
        while(k--) {
            pq.pop();
        }
        return pq.top();
    }
};