#include<bits/stdc++.h>
using namespace std;
int maximum(int& a, int b) {
    if(a > b) {
        return a;
    }
    return b;
}
class Solution {
public:
    bool f(unordered_map<char,int>& mp1, unordered_map<char,int>& mp2) {
        for(char letter='a'; letter<='z'; letter++) {
            if(mp1[letter] > 0 and mp2[letter] > 0) {
                return false;
            }
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        vector<unordered_map<char,int>> vec;
        for(string& word: words) {
            unordered_map<char,int> mp;
            for(char& letter: word) {
                mp[letter]++;
            }
            vec.push_back(mp);
        }
        int len = words.size(), answer = 0;
        for(int i=0; i<len-1; i++) {
            for(int j=i+1; j<len; j++) {
                if(this->f(vec[i],vec[j]) == true) {
                    answer = maximum(answer,words[i].length() * words[j].length());
                }
            }
        }
        return answer;
    }
};