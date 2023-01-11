#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check_upper(char& letter) {
        return letter>='A' and letter<='Z';
    }
    bool subsequence(string& query, string& pattern) {
        int index=0;
        for(char& letter: query) {
            if(letter==pattern[index]) {
                index++;
            }
            else if(letter != pattern[index] and check_upper(letter) == true) {
                return false;
            }
        }
        return index == pattern.length();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
        for(string& query: queries) {
            answer.push_back(subsequence(query,pattern));
        }
        return answer;
    }
};
int main() {
    Solution* obj;
    vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    vector<bool> answer = obj->camelMatch(queries,"FoBaT");
    for(bool res: answer) {
        cout<<res<<" ";
    }
    cout<<endl;
    return 0;
}