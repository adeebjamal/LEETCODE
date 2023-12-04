#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestGoodInteger(string num) {
        int len = num.length();
        string answer = "";
        for(int i = 0; i < len-2; i++) {
            if(num[i] == num[i+1] and num[i+1] == num[i+2]) {
                answer = max(answer, num.substr(i,3));
            }
        }
        return (answer == "000") ? "0" : answer;
    }
};