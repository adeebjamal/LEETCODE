#include<bits/stdc++.h>
using namespace std;
int res(int exp, int base) {
    if(base==1) {
        return 1;
    }
    int res=0;
    while(exp) {
        exp/=base;
        res++;
    }
    return res;
}
vector<int> powerfulIntegers(int x, int y, int bound) {
    int log1=res(bound,x), log2=res(bound,y);
    unordered_set<int> ans;
    for(int i=0; i<=log1; i++) {
        for(int j=0; j<=log2; j++) {
            int one=pow(x,i), two=pow(y,j);
            if(one+two<=bound) {
                ans.insert(one+two);
            }
        }
    }
    return vector<int>(ans.begin(),ans.end());
}
int main() {
    vector<int> ans={2,3,10};
    for(int& num: ans) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}