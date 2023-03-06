#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back(NULL);
        string answer = "";
        int curr_count = 1;
        for(int i=0; i<chars.size()-1; i++) {
            if(chars[i] == chars[i+1]) {
                curr_count++;
            }
            else if(chars[i] != chars[i+1] and curr_count == 1) {
                answer.push_back(chars[i]);
                curr_count = 1;
            }
            else {
                answer.push_back(chars[i]);
                for(char& digit: to_string(curr_count)) {
                    answer.push_back(digit);
                }
                curr_count = 1;
            }
        }
        chars = {};
        for(char& itr: answer) {
            chars.push_back(itr);
        }
        return answer.length();
    }
};