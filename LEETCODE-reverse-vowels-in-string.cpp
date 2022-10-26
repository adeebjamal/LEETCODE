#include<bits/stdc++.h>
using namespace std;
void swap(char& a, char& b) {
    char temp=a;
    a=b;
    b=temp;
}
bool isVowel(char& c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}
string reverseStr(string s) {
    int i=0, j=s.length()-1;
    while(i<j) {
        if(!isVowel(s[i])) {
            i++;
        }
        if(!isVowel(s[j])) {
            j--;
        }
        if(isVowel(s[i]) && isVowel(s[j])) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    return s;
}
int main() {
    cout<<reverseStr("leetcode")<<endl;
    return 0;
}