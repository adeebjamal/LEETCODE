#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
    int maxLevelSum(TreeNode* root) {
        int level=0, maxi=INT_MIN, ans=0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            level++;
            int len=q.size(), sum=0;
            for(int i=0; i<len; i++) {
                sum+= q.front()->data;
                if(q.front()->right != NULL) q.push(q.front()->right);
                if(q.front()->left != NULL) q.push(q.front()->left);
                q.pop();
            }
            if(sum>maxi) {
                maxi=sum;
                ans=level;
            }
        }
        return ans;
    }
};
int main() {
    TreeNode* root1=new TreeNode(1);
    root1->left=new TreeNode(7);
    root1->right=new TreeNode(0);
    root1->left->left=new TreeNode(7);
    root1->left->right=new TreeNode(-8);
    cout<<root1->maxLevelSum(root1);
    return 0;
}