#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,vector<int>> mp;    // player ID ----> result of all his matches
        for(vector<int>& match: matches) {
            mp[match[0]].push_back(1);
            mp[match[1]].push_back(-1);
        }
        vector<int> no_loss, one_loss;
        for(auto& it: mp) {
            int curr_ct= count(it.second.begin(),it.second.end(),-1);
            if(curr_ct==0) {
                no_loss.push_back(it.first);
            }
            else if(curr_ct==1) {
                one_loss.push_back(it.first);
            }
        }
        sort(no_loss.begin(),no_loss.end());
        sort(one_loss.begin(),one_loss.end());
        return {no_loss,one_loss};
    }
};
int main() {

    return 0;
}