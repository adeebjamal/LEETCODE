#include<bits/stdc++.h>
using namespace std;
int maxi(int& a, int b) {
    if(a > b) {
        return a;
    }
    return b;
}
vector<string> bigSorting(vector<string>& unsorted) {
    unordered_map<int,vector<string>> mp;
    int max_len = INT_MIN;
    for(string& num: unsorted) {
        mp[num.length()].push_back((num));
        max_len = maxi(max_len,num.length());
    }
    for(auto& itr: mp) {
        sort(itr.second.begin(),itr.second.end());
    }
    unsorted = {};
    for(int len=1; len<=max_len; len++) {
        for(string& num: mp[len]) {
            unsorted.push_back(num);
        }
    }
    return unsorted;
}
int main() {
    int n=0;
    cin>>n;
    vector<string> unsorted;
    for(int i=0; i<n; i++) {
        string str="";
        cin>>str;
        unsorted.push_back(str);
    }
    for(string& num: bigSorting(unsorted)) {
        cout<<num<<endl;
    }
    return 0;
}