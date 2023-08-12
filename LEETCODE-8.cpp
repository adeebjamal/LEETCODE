#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()) {
            return 0;
        }
        long long int number = 0;
        bool negative = false;
        int index = 0;
        while(index < s.length() and s[index] == ' ') {
            index++;
        }
        if(index == s.length()) {
            return 0;
        }
        if(s[index] == '-' or s[index] == '+') {
            negative = (s[index] == '-');
            index++;
        }
        while(s[index] >= '0' and s[index] <= '9' and index < s.length()) {
            number*= 10;
            number+= (s[index] - '0');
            if(number >= INT_MAX or number <= INT_MIN) {
                break;
            }
            index++;
        }
        if(negative == true) {
            number*= -1;
        }
        if(number >= INT_MAX) {
            number = INT_MAX;
        }
        if(number <= INT_MIN) {
            number = INT_MIN;
        }
        return number;
    }
};