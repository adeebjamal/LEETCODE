#include<bits/stdc++.h>
using namespace std;
int strStr(string haystack, string needle) {
    int pos=haystack.find(needle);
    if(pos>=0 || pos<haystack.length()) {
        return pos;
    } else {
        return -1;
    }
}
int main() {
    cout<<strStr("abcdefghi", "def")<<endl;
    cout<<strStr("abcdefg", "xyz")<<endl;
    return 0;
}