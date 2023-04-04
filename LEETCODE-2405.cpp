#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partitionString(string s) {
        unordered_map<int,int> mp;
        int answer=0;
        for(char& letter: s) {
            if(mp[letter] + 1 == 2) {
                answer++;
                mp.clear();
            }
            mp[letter]++;
        }
        return answer + 1;
    }
};
int main() {
    Solution* obj;
    cout<<obj->partitionString("abacaba")<<endl;
    cout<<obj->partitionString("ssssss")<<endl;
    return 0;
}