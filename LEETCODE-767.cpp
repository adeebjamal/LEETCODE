#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(char& letter: s) {
            mp[letter]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto& itr: mp) {
            pq.push({itr.second,itr.first});
        }
        string answer = "";
        while(pq.size() >= 2) {
            pair<int,char> p1 = pq.top();
            pq.pop();
            pair<int,char> p2 = pq.top();
            pq.pop();
            answer.push_back(p1.second);
            answer.push_back(p2.second);
            p1.first--;
            p2.first--;
            if(p1.first > 0) {
                pq.push({p1.first,p1.second});
            }
            if(p2.first > 0) {
                pq.push({p2.first,p2.second});
            }
        }
        if(pq.empty() == false) {
            pair<int,char> p = pq.top();
            if(p.first > 1) {
                return "";
            }
            answer.push_back(p.second);
        }
        return answer;
    }
};