#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> idx_a, idx_b, answer;
        int len_a = a.length(), len_b = b.length(), len = s.length();
        for(int i = 0; i <= len - len_a; i++) {
            if(s.substr(i, len_a) == a) {
                idx_a.push_back(i);
            } 
        }
        for(int j = 0; j <= len - len_b; j++) {
            if(s.substr(j, len_b) == b) {
                idx_b.push_back(j);
            }
        }
        for(int i = 0; i < idx_a.size(); i++) {
            for(int j = 0; j < idx_b.size(); j++) {
                if(abs(idx_a[i] - idx_b[j]) <= k) {
                    answer.push_back(idx_a[i]);
                    break;
                }
            }
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};