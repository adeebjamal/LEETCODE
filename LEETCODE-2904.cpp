#include<bits/stdc++.h>
using namespace std;
int mini(int& a, int b) {
    return (a < b) ? a : b;
}
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int len = s.length(), min_len = INT_MAX;
        vector<string> vec;
        for(int i=0; i<len; i++) {
            for(int j=1; j<len-i+1; j++) {
                string str = s.substr(i,j);
                int one = count(str.begin(),str.end(),'1');
                if(one == k) {
                    vec.push_back(str);
                    min_len = mini(min_len,str.length());
                }
            }
        }
        string answer = "zzzzzzzzzz";
        for(string& str: vec) {
            if(str.length() == min_len) {
                answer = min(answer,str);
            }
        }
        return (answer == "zzzzzzzzzz") ? "" : answer;
    }
};