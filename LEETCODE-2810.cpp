#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string finalString(string s) {
        string str = "";
        for(char& letter: s) {
            if(letter == 'i') {
                reverse(str.begin(),str.end());
            }
            else {
                str.push_back(letter);
            }
        }
        return str;
    }
};