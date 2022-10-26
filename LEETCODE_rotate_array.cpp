#include<bits/stdc++.h>
using namespace std;
vector<int> rotate(vector<int> &nums, int k) {
    deque<int> dup;
    for(int i: nums) {
        dup.push_back(i);
    }
    nums.clear();
    for(int i=0; i<k; i++) {
        dup.push_front(*(dup.end()-1));
        dup.erase(dup.end()-1);
    }
    for(int i: dup) {
        nums.push_back(i);
    }
    return nums;
}
int main() {
    vector<int> v1={1,2,3,4,5,6,7,8,9,0};
    vector<int> v2=rotate(v1,4);
    for(int i: v2) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}