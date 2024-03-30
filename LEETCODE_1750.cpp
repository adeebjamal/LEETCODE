#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(deque<char>& dq) {
        if(dq.back() == dq.front()) {
            char letter = dq.front();
            while(true) {
                if(dq.empty()) {
                    break;
                }
                else if(dq.front() == letter) {
                    dq.pop_front();
                }
                else {
                    break;
                }
            }
            while(true) {
                if(dq.empty()) {
                    break;
                }
                else if(dq.back() == letter) {
                    dq.pop_back();
                }
                else {
                    break;
                }
            }
            return true;
        }
        return false;
    }
    int minimumLength(string s) {
        if(s.length() == 1) {
            return 1;
        }
        deque<char> dq;
        for(char& letter: s) {
            dq.push_back(letter);
        }
        while(this->solve(dq)) {
            if(dq.size() == 1) {
                break;
            }
        }
        return dq.size();
    }
};