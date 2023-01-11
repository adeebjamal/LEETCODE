#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeGood(string s) {
        int len=s.length();
        for(int i=0; i<len-1; i++) {
            if(abs(s[i]-s[i+1]) == 32) {
                s.erase(i,2);
                len-=2;
                return makeGood(s);
            }
        }
        return s;
    }
};
int main() {
    Solution* obj;
    cout<<obj->makeGood("leEeetcode")<<endl;
    cout<<obj->makeGood("abBAcC")<<endl;
    cout<<obj->makeGood("s");
    return 0;
}