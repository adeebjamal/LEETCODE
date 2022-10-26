#include<bits/stdc++.h>
using namespace std;
int minimumAverageDifference(vector<int>& nums) {
    vector<long long int> arr;
    long long int sum=0;
    for(int& num: nums) {
        sum+= num*1LL;
        arr.push_back(sum);
    }
    int ans=0, min_gap=INT_MAX, len=arr.size();
    for(int i=0; i<len; i++) {
        long long int left=arr[i]/(i+1);
        long long int right=0;
        if(i != len-1) {
            right=(arr.back()-arr[i])/(len-i-1);
        }
        if(abs(left-right)<min_gap) {
            min_gap=abs(left-right);
            ans=i;
        }
    }
    return ans;
}
int main() {

    return 0;
}