#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mps, mpt;
        for(char& letter: s) {
            mps[letter]++;
        }
        for(char& letter: t) {
            mpt[letter]++;
        }
        int ans=0;
        for(char letter='a'; letter<='z'; letter++) {
            ans+= abs(mps[letter] - mpt[letter]);
        }
        return ans;
    }
};
int main() {
    string str1="leetcode", str2="coats";
    Solution* obj;
    cout<<obj->minSteps(str1,str2)<<endl;
    str1="night";
    str2="thing";
    cout<<obj->minSteps(str1,str2)<<endl;
    return 0;
}