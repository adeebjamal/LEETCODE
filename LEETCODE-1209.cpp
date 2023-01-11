#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int len=s.length();
        if(len<k) {
            return s;
        }
        stack<pair<char,int>> stk;
        for(char& letter: s) {
            if(stk.empty() or stk.top().first != letter) {
                stk.push({letter,1});
            }
            else {
                pair<char,int> p=stk.top();
                stk.pop();
                stk.push({letter,p.second+1});
            }
            if(stk.top().second==k) {
                stk.pop();
            }
        }
        s="";
        while(!stk.empty()) {
            for(int i=0; i<stk.top().second; i++) {
                s.push_back(stk.top().first);
            }
            stk.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
int main() {
    Solution* obj;
    cout<<obj->removeDuplicates("deeedbbcccbdaa",3)<<endl;
    cout<<obj->removeDuplicates("abcd",2)<<endl;
    cout<<obj->removeDuplicates("pbbcggttciiippooaais",2)<<endl;
    return 0;
}