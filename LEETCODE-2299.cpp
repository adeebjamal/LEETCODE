#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string str="";
    bool check(char& ch) {
        return binary_search(str.begin(),str.end(),ch);
    }
    bool strongPasswordCheckerII(string password) {
        int len=password.length();
        if(len<8) return false;
        string temp="!@#$%^&*()-+";
        sort(temp.begin(),temp.end());
        str=temp;
        bool upper=false, lower=false, digit=false, special=false;
        for(char& letter: password) {
            if(letter>='a' and letter<='z') lower=true;
            else if(letter>='A' and letter<='Z') upper=true;
            else if(letter>='0' and letter<='9') digit=true;
            else if(check(letter)) special=true;
        } 
        for(int i=0; i<len-1; i++) {
            if(password[i]==password[i+1]) return false;
        }
        return lower and upper and special and digit;
    }
};
int main() {

    return 0;
}