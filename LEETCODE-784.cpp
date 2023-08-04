#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_set<string> answer;
    void solve(int index, string& str) {
        if(index == str.length()) {
            this->answer.insert(str);
            return;
        }
        // Not changing the case
        this->solve(index+1,str);
        // Changing the case
        if(str[index] >='a' and str[index] <= 'z') {
            str[index] = str[index] - 'a' + 'A';
        }
        else if(str[index] >= 'A' and str[index] <= 'Z') {
            str[index] = str[index] - 'A' + 'a';
        }
        this->solve(index+1,str);
    }
    vector<string> letterCasePermutation(string s) {
        this->solve(0,s);
        return vector<string>(this->answer.begin(),this->answer.end());
    }
};