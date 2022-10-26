#include<bits/stdc++.h>
using namespace std;
string digitSum(string s, int k) {
    if(s.length()<=k) {
        return s;
    }
    vector<string> vec;
    int len=s.length();
    string temp="";
    for(int i=0; i<len; i++) {
        if(temp.length()==k) {
            vec.push_back(temp);
            temp="";
            i--;
        }
        else {
            temp.push_back(s[i]);
        }
    }
    if(temp.length()>0) {
        vec.push_back(temp);
    }
    s="";
    for(string& num: vec) {
        int sum=0;
        for(char& digit: num) {
            sum+= digit-'0';
        }
        s+= to_string(sum);
    }
    if(s.length()>k) {
        return digitSum(s,k);
    }
    return s;
}
int main() {
    string s="";
    cin>>s;
    int k=0;
    cin>>k;
    cout<<digitSum(s,k)<<endl;
    return 0;
}