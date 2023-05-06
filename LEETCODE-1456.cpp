#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int answer = INT_MIN, count = 0;
        string vowel = "aeiou";
        for(int i=0; i<k; i++) {
            if(binary_search(vowel.begin(),vowel.end(),s[i]) == true) {
                count++;
            }
        }
        answer = max(answer,count);
        for(int i=k; i<s.length(); i++) {
            if(binary_search(vowel.begin(),vowel.end(),s[i]) == true) {
                count++;
            }
            if(binary_search(vowel.begin(),vowel.end(),s[i-k]) == true) {
                count--;
            }
            answer = max(answer,count);
        }
        return answer;
    }
};