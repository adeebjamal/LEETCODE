#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long coloredCells(int n) {
        long long int num = n*1LL, answer = 0;
        answer+= num*num;
        num--;
        answer+= num*num;
        return answer;
    }
};