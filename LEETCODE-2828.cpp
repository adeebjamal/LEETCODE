#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int index=0;
        for(string& str: words) {
            if(str[0] == s[index]) {
                index++;
            }
            else {
                return false;
            }
        }
        return index == s.length();
    }
};