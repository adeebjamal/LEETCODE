#include<bits/stdc++.h>
using namespace std;
void U2L(string &s) {
    for(int i=0; i<s.length(); i++) {
        s[i]=tolower(s[i]);
    }
}
bool palindrome(string& s) {
    U2L(s);
    int start=0, end=s.length()-1;
    while(start<end) {
        if(s[start++]!=s[end--]) {
            return false;
        }
    }
    return true;
}
int main() {
    string str="";
    getline(cin,str);
    string str2="";
    for(char& c: str){
        if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')) {
            str2.push_back(c);
        }
    }
    str.clear();
    cout<<palindrome(str2)<<endl;
    return 0;
}