#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int first=0, second=0, len1=nums1.size(), len2=nums2.size();
        vector<vector<int>> answer;
        int next=0;
        for(int i=0; i<len1; i++) {
            if(i+1<len1) {
                next=i+1;
            }
            for(int j=0; j<len2; j++) {
                if(nums1[i]+nums2[j] < nums1[next]+nums2[0]) {
                    answer.push_back({nums1[i],nums2[j]});
                    if(answer.size()==k) {
                        return answer;
                    }
                }
                else {
                    break;
                }
            }
        }
        return answer;
    }
};
void display(vector<vector<int>> mat) {
    for(vector<int>& pair: mat) {
        for(int& num: pair) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
int main() {
    Solution* obj=new Solution();
    vector<int> nums1={1,7,11}, nums2={2,4,6};
    display(obj->kSmallestPairs(nums1,nums2,3));
    nums1={1,1,2}, nums2={1,2,3};
    display(obj->kSmallestPairs(nums1,nums2,2));
    nums1={1,2}, nums2={3};
    display(obj->kSmallestPairs(nums1,nums2,3));
    return 0;
}