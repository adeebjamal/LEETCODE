#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> level_order;
        while(!q.empty()) {
            int len=q.size();
            vector<int> level;
            for(int i=0; i<len; i++) {
                level.push_back(q.front()->val);
                for(Node* &node: q.front()->children) {
                    if(node != NULL) q.push(node);
                }
                q.pop();
            }
            level_order.push_back(level);
        }
        return level_order;
    }
};
int main() {
    return 0;
}