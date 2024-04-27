#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> hash(deadends.begin(), deadends.end()), visited;
        if(hash.find("0000") != hash.end()) {
            return -1;
        }
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visited.insert("0000");
        while(q.empty() == false) {
            string number = q.front().first;
            int moves = q.front().second;
            q.pop();
            if(number == target) {
                return moves;
            }
            for(int i = 0; i < 4; i++) {
                for(int delta: {-1, 1}) {
                    int digit = (number[i] - '0' + delta + 10) % 10;
                    string newNumber = number;
                    newNumber[i] = digit + '0';
                    if(visited.find(newNumber) == visited.end() and hash.find(newNumber) == hash.end()) {
                        q.push({newNumber, moves + 1});
                        visited.insert(newNumber);
                    }
                }
            }
        }
        return -1;
    }
};