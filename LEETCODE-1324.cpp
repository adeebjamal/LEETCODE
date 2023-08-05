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
    vector<string> printVertically(string s) {
        vector<string> words;
        string word = "";
        int maxLen = 0;
        for(char& ch: s) {
            if(ch == ' ') {
                words.push_back(word);
                maxLen = maximum(maxLen,word.length());
                word = "";
            }
            else {
                word.push_back(ch);
            }
        }
        words.push_back(word);
        maxLen = maximum(maxLen,word.length());     // <----- IMPORTANT
        vector<string> answer;
        for(int i=0; i<maxLen; i++) {
            string str = "";
            for(string& word: words) {
                if(i < word.length()) {
                    str.push_back(word[i]);
                }
                else {
                    str.push_back(' ');
                }
            }
            while(str.back() == ' ') {
                str.pop_back();
            }
            answer.push_back(str);
        }
        return answer;
    }
};
int main() {
    Solution* obj = new Solution();
    vector<string> answer = obj->printVertically("HOW IS IT GOING");
    for(string& str: answer) {
        cout<<str<<endl;
    }
    return 0;
}