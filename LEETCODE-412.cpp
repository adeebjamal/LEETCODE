#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        int three = 0, five = 0;
        for(int num=1; num<=n; num++) {
            three++;
            five++;
            if(three == 3 and five == 5) {
                answer.push_back("FizzBuzz");
                three = 0;
                five = 0;
            }
            else if(three == 3) {
                answer.push_back("Fizz");
                three = 0;
            }
            else if(five == 5) {
                answer.push_back("Buzz");
                five = 0;
            }
            else {
                answer.push_back(to_string(num));
            }
        }
        return answer;
    }
};