#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubstrings(string s, char c) {
        int count = 0;
        for(char& letter : s) {
            if(letter == c) {
                count++;
            }
        }
        return count + count * (count - 1) / 2;
    }
};