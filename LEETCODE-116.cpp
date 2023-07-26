#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) {
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int len = q.size();
            for(int i=0; i<len; i++) {
                Node* curr_node = q.front();
                q.pop();
                if(i != len-1) {
                    curr_node->next = q.front();
                }
                if(curr_node->left != NULL) {
                    q.push(curr_node->left);
                }
                if(curr_node->right != NULL) {
                    q.push(curr_node->right);
                }
            }
        }
        return root;
    }
};