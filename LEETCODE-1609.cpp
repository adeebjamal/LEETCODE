#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    bool odd_increasing(vector<int>& nums) {
        if(nums[0]%2==0) return false;
        int len=nums.size();
        for(int i=0; i<len-1; i++) {
            if(nums[i]>=nums[i+1] || nums[i]%2==0) {
                return false;
            }
        }
        if(nums[len-1]%2==0) return false;
        return true;
    }
    bool even_decreasing(vector<int>& nums) {
        if(nums[0]%2==1) return false;
        int len=nums.size();
        for(int i=0; i<len-1; i++) {
            if(nums[i]<=nums[i+1] || nums[i]%2==1) {
                return false;
            }
        }
        if(nums[len-1]%2==1) return false;
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool even=true;
        while(!q.empty()) {
            int len=q.size();
            vector<int> level;
            for(int i=0; i<len; i++) {
                level.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            if(even) {
                if(odd_increasing(level)==false) return false;
            }
            else {
                if(even_decreasing(level)==false) return false;
            }
            even=!even;
        }
        return true;
    }
};
int main() {

    return 0;
}