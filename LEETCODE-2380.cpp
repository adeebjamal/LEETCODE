#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(string& str, int& length) {
        bool result=false;
        for(int i=0; i<length-1;) {
            if(str[i]=='0' and str[i+1]=='1') {
                result=true;
                str[i]='1';
                str[i+1]='0';
                i+=2;
            }
            else {
                i++;
            }
        }
        return result;
    }
    int secondsToRemoveOccurrences(string s) {
        int time=0, length=s.length();
        while(solve(s,length)) {
            time++;
        }
        return time;
    }
};
int main() {
    Solution* obj;
    cout<<obj->secondsToRemoveOccurrences("0110101")<<endl;
    cout<<obj->secondsToRemoveOccurrences("11100");
    return 0;
}