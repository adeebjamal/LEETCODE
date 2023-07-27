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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        vector<vector<int>> answer;
        queue<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            int len = st.size();
            vector<int> row;
            for(int i=0; i<len; i++) {
                row.push_back(st.front()->val);
                if(st.front()->left != NULL) {
                    st.push(st.front()->left);
                }
                if(st.front()->right != NULL) {
                    st.push(st.front()->right);
                }
                st.pop();
            }
            answer.push_back(row);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};