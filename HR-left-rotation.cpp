// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n=0, k=0;
    cin>>n>>k;
    deque<int> dq;
    for(int i=0; i<n; i++) {
        int x=0;
        cin>>x;
        dq.push_back(x);
    }
    while(k--) {
        dq.push_back(dq.front());
        dq.pop_front();
    }
    for(int& num: dq) {
        cout<<num<<" ";
    }
    return 0;
}