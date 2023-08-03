#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string v="AEIOUaeiou";
    bool f(char& ch) {
        return binary_search(v.begin(),v.end(),ch);
    }
    string sortVowels(string s) {
        vector<int> idx;
        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++) {
            if(this->f(s[i])) {
                idx.push_back(i);
                mp[s[i]]++;
            }
        }
        int start=0;
        for(char& ch: this->v) {
            while(mp[ch]--) {
                s[idx[start++]]=ch;
            }
        }
        return s;
    }
};