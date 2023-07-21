#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
vector<int> leftView(Node *root) {
    if(root == NULL) {
        return {};
    }
    vector<int> answer;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int len = q.size();
        for(int i=0; i<len; i++) {
            if(i == 0) {
                answer.push_back(q.front()->data);
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
    return answer;
}