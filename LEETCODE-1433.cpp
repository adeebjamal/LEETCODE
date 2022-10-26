#include<bits/stdc++.h>
using namespace std;
bool check(string& s1, string& s2, int& len) {
    for(int i=0; i<len; i++) {
        if(s1[i]<s2[i]) {
            return false;
        }
    }
    return true;
}
bool checkIfCanBreak(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int len=s1.length();
    return check(s1,s2,len) || check(s2,s1,len);
}
int main() {
    string s1="", s2="";
    cin>>s1>>s2;
    cout<<checkIfCanBreak(s1,s2);
    return 0;
}