#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0) return 0;
        int sign=1;
        if(num<0) {
            sign=-1;
            num=abs(num);
        }
        int zeros=0;
        string number="";
        while(num) {
            int digit=num%10;
            if(digit==0) zeros++;
            else number.push_back(digit+'0');
            num/=10;
        }
        sort(number.begin(),number.end());
        if(sign==-1) {
            long long int ans=0;
            reverse(number.begin(),number.end());
            for(char& digit: number) {
                ans=ans*10 + (digit-'0');
            }
            while(zeros--) {
                ans*=10;
            }
            return ans*sign;
        }
        long long int ans=(number[0]-'0')*1LL;
        while(zeros--) {
            ans=ans*10 + 0;
        }
        for(int i=1; i<number.length(); i++) {
            ans=ans*10 + (number[i]-'0');
        }
        return ans*sign;
    }
};
int main() {
    Solution* obj;
    cout<<obj->smallestNumber(310)<<endl;
    cout<<obj->smallestNumber(-7605)<<endl;
    return 0;
}