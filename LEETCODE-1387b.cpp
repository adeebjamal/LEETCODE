#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> getKth(int& low, int& high) {
    vector<pair<int,int>> ans;
    for(int i=low; i<=high; i++) {
        int num=i;
        int ct=0;
        while(num != 1) {
            if(num & 1) {
                num=(num*3)+1;
                ct++;
            }
            else {
                num/=2;
                ct++;
            }
        }
        ans.push_back({i,ct});
    }
    return ans;
}
int main() {
    int low=1, high=100;
    vector<pair<int,int>> ans=getKth(low,high);
    for(pair<int,int>& p: ans) {
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}