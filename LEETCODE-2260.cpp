#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,vector<int>> mp;
        int len=cards.size();
        for(int i=0; i<len; i++) {
            mp[cards[i]].push_back(i);
        }
        int global_min=INT_MAX;
        for(auto& it: mp) {
            int local_min=INT_MAX, curr_len=it.second.size();
            for(int i=0; i<curr_len-1; i++) {
                local_min=min(local_min, it.second[i+1]-it.second[i]+1);
            }
            global_min=min(global_min,local_min);
        }
        if(global_min==INT_MAX) {
            return -1;
        }
        return global_min;
    }
};
int main() {

}