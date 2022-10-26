#include<bits/stdc++.h>
using namespace std;
bool check(string s, string target) {
    return s.length()==target.length() && (s+s).find(target) != string::npos;
}
int main() {
    string s="abcde";
    cout<<(s+s).find("cdeab")<<endl;
    return 0;
}