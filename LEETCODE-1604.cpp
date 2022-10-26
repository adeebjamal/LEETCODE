#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMins(string& s) {
        int ans=0;
        string t="";
        t.push_back(s[0]);
        t.push_back(s[1]);
        ans+= stoi(t) * 60;
        t="";
        t.push_back(s[3]);
        t.push_back(s[4]);
        ans+= stoi(t);
        return ans;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string,vector<int>> mp;
        int len=keyName.size();
        for(int i=0; i<len; i++) {
            mp[keyName[i]].push_back(getMins(keyTime[i]));
        }
        vector<string> ans;
        for(auto& it: mp) {
            sort(it.second.begin(),it.second.end());
            int len=it.second.size();
            for(int i=2; i<len; i++) {
                int t1=it.second[i-2], t2=it.second[i];
                if(t2>=t1 && (t2-t1)<=60) {
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}