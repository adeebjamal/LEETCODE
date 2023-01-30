#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int alternateDigitSum(int n) {
        int sum=0;
        bool positive=true;
        string number=to_string(n);
        for(char& digit: number) {
            if(positive) {
                sum+= (digit-'0');
            }
            else {
                sum-= (digit-'0');
            }
            positive= !positive;
        }
        return sum;
    }
};