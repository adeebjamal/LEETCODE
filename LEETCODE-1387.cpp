#include<bits/stdc++.h>
using namespace std;
int getKth(int& lo, int& hi, int& k) {
    vector<pair<int,int>> vec;
    for(int i=lo; i<=hi; i++) {
        int num=i;
        int ct=0;
        while(num != 1) {
            if(num & 1) {
                num= (num*3)+1;
                ct++; 
            }
            else {
                num/=2;
                ct++;
            }
        }
        vec.push_back({ct,i});
    }
    sort(vec.begin(),vec.end());
    return vec[k-1].second;
}
int main() {
    int low=0,high=0,k=0;
    cin>>low>>high>>k;
    cout<<getKth(low,high,k)<<endl;
    return 0;
}