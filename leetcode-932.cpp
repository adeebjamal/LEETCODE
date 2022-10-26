#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t) {
    int curr=0;
    for(char& letter: t) {
        if(letter == s[curr]) {
            curr++;
        }
    }
    return curr==s.length();
}
int main() {
    string s="", t="";
    cin>>s>>t;
    cout<<isSubsequence(s,t);
    return 0;
}