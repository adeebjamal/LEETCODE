#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        unordered_map<string, unordered_set<int>> hash;
        for(int index = 0; index < arr.size(); index++) {
            for(int len = 1; len <= arr[index].length(); len++) {
                for(int i = 0; i <= arr[index].length() - len; i++) {
                    string subString = "";
                    for(int k = i; k <= i + len - 1; k++) {
                        subString.push_back(arr[index][k]);
                    }
                    hash[subString].insert(index);
                }
            }
        }
        vector<string> answer(arr.size(), "zzzzzzzzzzzzzzzzzzzzzzzzz");
        for(auto& itr: hash) {
            if(itr.second.size() == 1) {
                if(answer[*itr.second.begin()].length() > itr.first.length()) {
                    answer[*itr.second.begin()] = itr.first;
                }
                else if(answer[*itr.second.begin()].length() == itr.first.length()) {
                    answer[*itr.second.begin()] = min(answer[*itr.second.begin()], itr.first);
                }
            }
        }
        for(string& str: answer) {
            if(str == "zzzzzzzzzzzzzzzzzzzzzzzzz") {
                str = "";
            }
        }
        return answer;
    }
};