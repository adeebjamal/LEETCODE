#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long int answer = 0;
        int length = 0;
        unordered_map<int,int> mp;
        int number = 1;
        while(length != n) {
            if(mp[number] == 0) {
                answer+= number;
                mp[target-number] = 1;
                length++;
            }
            number++;
        }
        return answer;
    }
};