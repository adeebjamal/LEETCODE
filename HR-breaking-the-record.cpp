// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true
#include <bits/stdc++.h>
using namespace std;
vector<int> breakingRecords(vector<int>& scores) {
    int mini = INT_MAX, maxi = INT_MIN, min_count = -1, max_count = -1;
    for(int& score: scores) {
        if(score < mini) {
            mini = score;
            min_count++;
        }
        if(score > maxi) {
            maxi = score;
            max_count++;
        }
    }
    return {max_count, min_count};
}
int main() {
    int len=0;
    cin>>len;
    vector<int> nums;
    for(int i=0; i<len; i++) {
        int x=0;
        cin>>x;
        nums.push_back(x);
    }
    for(int& num: breakingRecords(nums)) {
        cout<<num<<" ";
    }
    return 0;
}