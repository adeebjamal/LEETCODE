#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper=0, lower=0, len=word.length();
        for(char& letter: word) {
            if(letter>='A' and letter<='Z') {
                upper++;
            }
            else if(letter>='a' and letter<='z') {
                lower++;
            }
        }
        if(word[0]>='A' and word[0]<='Z' and lower==len-1) {
            return true;
        }
        return upper==len or lower==len;
    }
};
int main() {
    Solution* obj;
    cout<<obj->detectCapitalUse("USA")<<endl;
    cout<<obj->detectCapitalUse("leetcode")<<endl;
    cout<<obj->detectCapitalUse("Google")<<endl;
    cout<<obj->detectCapitalUse("FlaG")<<endl;
    return 0;
}