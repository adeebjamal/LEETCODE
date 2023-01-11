#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> ump;
        for(char& letter: s) {
            ump[letter]++;
        }
        map<int,vector<char>> mp;
        for(auto& itr: ump) {
            mp[itr.second].push_back(itr.first);
        }
        s="";
        for(auto& itr: mp) {
            for(char& letter: itr.second) {
                for(int i=0; i<itr.first; i++) {
                    s.push_back(letter);
                }
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
int main() {
    Solution* obj;
    cout<<obj->frequencySort("tree")<<endl;
    cout<<obj->frequencySort("cccaaa")<<endl;
    cout<<obj->frequencySort("Aabb")<<endl;
    return 0;
}