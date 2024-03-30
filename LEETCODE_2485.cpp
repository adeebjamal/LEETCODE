#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotInteger(int n) {
        for(int i = 0; i <= n; i++) {
            int sum1 = i * ( i + 1 ) / 2;
            int sum2 = (n * (n + 1) / 2) - sum1 + i;
            if(sum1 == sum2) {
                return i;
            }
        }
        return -1;
    }
};