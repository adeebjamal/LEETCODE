#include<bits/stdc++.h>
using namespace std;
void swap(char& a, char& b) {
    char temp=a;
    a=b;
    b=temp;
}
string reverseOnlyLetters(string& s) {
    vector<char> ans;
    vector<pair<char,int>> vec;
    for(int i=0; i<s.length(); i++) {
        pair<char, int> p;
        if(!(s[i]>='a' && s[i]<='z')) {
            if(!(s[i]>='A' && s[i]<='Z')) {
                p={s[i],i};
                vec.push_back(p);
            }
        } else {
            ans.push_back(s[i]);
        }
    }
}
int main() {
    string str="a-bC-dEf-ghIJ";
    cout<<reverseOnlyLetters(str)<<endl;
    return 0;
}