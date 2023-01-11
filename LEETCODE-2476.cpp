#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class Solution {
public:
    void inorder(TreeNode* &root, vector<int>& nums) {
        if(root == NULL) {
            return;
        }
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    int lowerbound(vector<int>& nums, int& key) {
        int start=0, end=nums.size()-1;
        while(start<=end) {
            int mid=start+(end-start)/2;
            if(nums[mid]<=key) {
                start=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return end;
    }
    int upperbound(vector<int>& nums, int& key) {
        int start=0, end=nums.size()-1;
        while(start<=end) {
            int mid=start+(end-start)/2;
            if(nums[mid]>=key) {
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        return start;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        inorder(root,nums);
        vector<vector<int>> answer;
        for(int& query: queries) {
            int lb=lowerbound(nums,query);
            int ub=upperbound(nums,query);
            if(lb>=0 and lb<nums.size() and nums[lb]<=query) {
                lb=nums[lb];
            }
            else {
                lb=-1;
            }
            if(ub>=0 and ub<nums.size() and nums[ub]>=query) {
                ub=nums[ub];
            }
            else {
                ub=-1;
            }
            answer.push_back({lb,ub});
        }
        return answer;
    }
};