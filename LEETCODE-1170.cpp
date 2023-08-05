#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(string& str) {
        char smallest = *min_element(str.begin(),str.end());
        return count(str.begin(),str.end(),smallest);
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> w, answer;
        for(string& word: words) {
            w.push_back(this->f(word));
        }
        for(string& query: queries) {
            int res = this->f(query);
            int count = 0;
            for(int& num: w) {
                if(res < num) {
                    count++;
                }
            }
            answer.push_back(count);
        }
        return answer;
    }
};