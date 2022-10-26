#include<bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int len_p= p.length();
    int len_s=s.length();
    sort(p.begin(), p.end());
    for(int i=0; i<=len_s-len_p; i++) {
        if(binary_search(p.begin(), p.end(), s[i])) {
            string temp= s.substr(i,len_p);
            sort(temp.begin(), temp.end());
            if(temp==p) {
                ans.push_back(i);
            }
        }
    }
    return ans;
}
int main() {
    string s="cbaebabacd";
    string p="abc";
    vector<int> ans=findAnagrams(s,p);
    for(int& i: ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}