#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
    public:
    vector<int> inorder;
    void dfs(Node* root) {
        if(root == NULL) {
            return;
        }
        dfs(root->left);
        inorder.push_back(root->data);
        dfs(root->right);
    }
    bool isBST(Node* root) {
        dfs(root);
        for(int i=0; i<inorder.size()-1; i++) {
            if(inorder[i] >= inorder[i+1]) {
                return false;
            }
        }
        return true;
    }
};