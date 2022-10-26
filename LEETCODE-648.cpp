#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> words;
        string temp="";
        for(char& letter: sentence) {
            if(letter != ' ') {
                temp.push_back(letter);
            }
            else {
                words.push_back(temp);
                temp="";
            }
        }
        if(temp.size()>0) words.push_back(temp);
        for(string& root: dictionary) {
            int curr_len=root.length();
            for(string& word: words) {
                if(root == word.substr(0,curr_len)) {
                    word=root;
                }
            }
        }
        sentence="";
        for(string& word: words) {
            sentence+= word + ' ';
        }
        sentence.pop_back();
        return sentence;
    }
};
int main() {
    return 0;
}