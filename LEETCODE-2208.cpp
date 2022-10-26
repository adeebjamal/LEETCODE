#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(),nums.end());
        double sum=accumulate(nums.begin(),nums.end(),0.0), curr_sum=0;
        int ans=0;
        while(sum-curr_sum > sum/2) {
            double top=pq.top();
            pq.pop();
            curr_sum+= top/2;
            pq.push(top/2);
            ans++;
        }
        return ans;
    }
};
int main() {
    Solution* obj;
    vector<int> nums={5,19,8,1};
    cout<<obj->halveArray(nums)<<endl;
    nums={3,8,20};
    cout<<obj->halveArray(nums)<<endl;
    return 0;
}