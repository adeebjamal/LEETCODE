#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumofdigits(int& num) {
        int sum=0;
        int num1=num;
        while(num1) {
            sum+= num1%10;
            num1/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        priority_queue<pair<int,int>> pq;   // <sum of digits, number>
        for(int& num: nums) {
            pq.push({sumofdigits(num),num});
        }
        long long int maxi=-1;
        while(true) {
            pair<int,int> temp=pq.top();
            pq.pop();
            if(pq.empty()) break;
            if(temp.first == pq.top().first) {
                maxi=max(maxi, temp.second*1LL + pq.top().second*1LL);
            }
        }
        return maxi;
    }
};
int main() {
    Solution* obj;
    vector<int> nums={18,43,36,13,7};
    cout<<obj->maximumSum(nums)<<endl;
    nums={10,12,19,14};
    cout<<obj->maximumSum(nums)<<endl;
    return 0;
}