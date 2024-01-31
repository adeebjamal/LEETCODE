#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int length = temperatures.size();
        vector<int> answer(length, 0);
        stack<pair<int,int>> st;
        for(int i = 0; i < length; i++) {
            while(st.top().first < temperatures[i]) {
                answer[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return answer;
    }
};