#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        string answer="";
        for(char& letter: s) {
            if(letter != '*') {
                answer.push_back(letter);
            }
            else if(letter=='*' and answer.length() > 0) {
                answer.pop_back();
            }
        }
        return answer;
        // stack<char> st;
        // for(char& letter: s) {
        //     if(letter != '*') {
        //         st.push(letter);
        //     }
        //     else if(letter=='*' and !st.empty()) {
        //         st.pop();
        //     }
        // }
        // s="";
        // while(!st.empty()) {
        //     s.push_back(st.top());
        //     st.pop();
        // }
        // reverse(s.begin(),s.end());
        // return s;
    }
};