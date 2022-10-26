#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<string>& suits) {
        unordered_set<string> myset(suits.begin(),suits.end());
        if(myset.size()==1) return "Flush";
        unordered_map<int,int> mp;
        for(int& rank: ranks) {
            mp[rank]++;
            if(mp[rank]==3) {
                return "Three of a Kind";
            }
        }
        for(auto& it: mp) {
            if(it.second==2) {
                return "Pair";
            }
        }
        return "High Card";
    }
};
int main() {
    vector<int> r1={13,2,3,1,9}, r2={4,4,2,4,4}, r3={10,10,2,12,9};
    vector<string> s1={"a","a","a","a","a"}, s2={"d","a","a","b","c"}, s3={"a","b","c","a","d"};
    Solution ob;
    cout<<ob.bestHand(r1,s1)<<endl;
    cout<<ob.bestHand(r2,s2)<<endl;
    cout<<ob.bestHand(r3,s3)<<endl;
    return 0;
}