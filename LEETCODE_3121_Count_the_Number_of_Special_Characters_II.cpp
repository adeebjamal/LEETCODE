#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> lower, upper;
        for(char letter = 'a'; letter <= 'z'; letter++) {
            lower[letter] = -1;
            upper[letter - 'a' + 'A'] = -1;
        }

        for(int idx = 0; idx < word.length(); idx++) {
            char letter = word[idx];
            if(letter >= 'a' and letter <= 'z') {
                lower[letter] = idx;
            }
            else if(letter >= 'A' and letter <= 'Z' and upper[letter] == -1) {
                upper[letter] = idx;
            }
        }

        int answer = 0;
        for(char small = 'a'; small <= 'z'; small++) {
            char capital = small - 'a' + 'A';
            if(lower[small] == -1) {
                continue;
            }
            if(upper[capital] > lower[small]) {
                answer++;
            }
        }

        return answer;
    }
};