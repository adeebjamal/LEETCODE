#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int len=changed.size();
        if(len % 2 == 1) {
            return {};
        }
        vector<int> ans;
        map<int,int> mp;
        for(int& num: changed) {
            mp[num]++;
        }
        sort(changed.begin(),changed.end());
        for(int& num: changed) {
            if(mp[num]==0) continue;
            else if(mp[2*num]==0) return {};
            ans.push_back(num);
            mp[num]--;
            mp[2*num]--;
        }
        return ans;
    }
};
int main() {

    return 0;
}