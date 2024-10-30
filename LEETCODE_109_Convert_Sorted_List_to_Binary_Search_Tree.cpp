#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode() {}
    ListNode(int val) { this->val = val; }
    ListNode(int val, ListNode* next) { this->val = val; this->next = next; }
};
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {}
    TreeNode(int val) { this->val = val; }
    TreeNode(int val, TreeNode* left, TreeNode* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class Solution {
    TreeNode* f(vector<int>& nums, int left, int right) {
        if(left > right) {
            return NULL;
        }
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = this->f(nums, left, mid - 1);
        node->right = this->f(nums, mid + 1, right);
        return node;
    }
    public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        return this->f(nums, 0, nums.size() - 1);
    }
};