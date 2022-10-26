#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> level_order;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int len=q.size();
            for(int i=0; i<len; i++) {
                level.push_back(q.front()->val);
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
            level_order.push_back(level);
        }
        int len=level_order.size();
        if(len==1) return level_order;
        for(int i=1; i<len; i+=2) {
            reverse(level_order[i].begin(),level_order[i].end());
        } 
        return level_order;
    }
};
int main() {

    return 0;
}