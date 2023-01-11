#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        long long int score=0;
        for(int i=0; i<k; i++) {
            double temp=pq.top()*1.0;
            pq.pop();
            score+=temp;
            pq.push(ceil(temp/3.0));
        }
        return score;
    }
};
int main() {
    vector<int> nums={10,10,10,10,10};
    Solution* obj;
    cout<<obj->maxKelements(nums,5)<<endl;
    nums={1,10,3,3,3};
    cout<<obj->maxKelements(nums,3)<<endl;
    return 0;
}