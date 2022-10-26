#include<bits/stdc++.h>
using namespace std;
string s1="", s2="";
int maxDiff(int num) {
    string num1=to_string(num), num2=to_string(num);
    char change=' ';
    int len=num1.length();
    for(int i=0; i<len; i++) {
        if(num1[i] != '9') {
            change=num1[i];
            for(int j=i; j<len; j++) {
                if(num1[j]==change) {
                    num1[j]='9';
                }
            }
            break;
        }
    }
    if(num2[0]=='1') {
        int i=0;
        while(num2[i]=='1' || num2[i]=='0') {
            i++;
        }
        change=num2[i];
        while(i<len) {
            if(num2[i]==change) {
                num2[i]='0';
            }
            i++;
        }
    }
    else if(num2[0] != '1') {
        change=num2[0];
        for(int i=0; i<len; i++) {
            if(num2[i]==change) {
                num2[i]='1';
            }
        }
    }
    return stoi(num1)-stoi(num2);
}
int main() {
    int num=0;
    cin>>num;
    cout<<maxDiff(num);
    return 0;
}