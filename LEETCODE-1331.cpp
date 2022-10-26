#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> my_set(arr.begin(),arr.end());
        int index=0;
        unordered_map<int,int> mp;
        for(auto num=my_set.begin(); num!=my_set.end(); num++) {
            mp[*num]=index++;
        }
        for(int& num: arr) {
            num=mp[num]+1;
        }
        return arr;
    }
};
int main() {

    return 0;
}