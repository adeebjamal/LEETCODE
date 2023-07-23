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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int answer = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len = q.size(), curr_sum = 0;
            for(int i=0; i<len; i++) {
                curr_sum+= q.front()->val;
                if(q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                answer = curr_sum;
                q.pop();
            }
        }
        return answer;
    }
};