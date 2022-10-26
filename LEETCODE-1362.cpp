#include<bits/stdc++.h>
using namespace std;
vector<int> factor(int num) {
    int root=sqrt(num);
    for(int i=root; i>0; i--) {
        if(num % i == 0) {
            return {i,num/i};
        }
    }
    return {1,num};
}
vector<int> closestDivisors(int num) {
    vector<int> ans1=factor(num+1), ans2=factor(num+2);
    if(abs(ans1[0]-ans1[1]) < abs(ans2[0]-ans2[1])) {
        return ans1;
    }
    return ans2;
}
int main() {
    int tc=0;
    cin>>tc;
    while(tc--) {
        int num=0;
        cin>>num;
        for(int& fact: closestDivisors(num)) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}