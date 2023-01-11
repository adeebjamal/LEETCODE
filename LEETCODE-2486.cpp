#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int index=0;
        for(char& letter: s) {
            if(letter == t[index]) {
                index++;
            }
        }
        return t.length()-index;
    }
};
int main() {
    Solution *obj;
    cout<<obj->appendCharacters("coaching","coding")<<endl;
    cout<<obj->appendCharacters("abcde","a")<<endl;
    cout<<obj->appendCharacters("z","abcde")<<endl;
    return 0;
}