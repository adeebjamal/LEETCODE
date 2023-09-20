#include<bits/stdc++.h>
using namespace std;
int main() {
    int len=0;
    cin>>len;
    unordered_map<string,int> mp;
    for(int i=0; i<len; i++) {
        string str="";
        cin>>str;
        mp[str]++;
    }
    cin>>len;
    for(int i=0; i<len; i++) {
        string str="";
        cin>>str;
        cout<<mp[str]<<endl;
    }
    return 0;
}