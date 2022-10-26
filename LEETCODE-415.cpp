#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1=="0") return num2;
        else if(num2=="0") return num1;
        int sum=0, end1=num1.length()-1, end2=num2.length()-1;
        string res="";
        while(end1>=0 and end2>=0) {
            sum+=((num1[end1--]-'0')+(num2[end2--]-'0'));
            res.push_back(sum%10 + '0');
            sum/=10;
        }
        while(end1>=0) {
            sum+= num1[end1--]-'0';
            res.push_back(sum%10 + '0');
            sum/=10;
        }
        while(end2>=0) {
            sum+= num2[end2--]-'0';
            res.push_back(sum%10 + '0');
            sum/=10;
        }
        if(sum>0) {
            res.push_back(sum+'0');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
int main() {
    Solution* obj;
    cout<<obj->addStrings("11","123")<<endl;
    cout<<obj->addStrings("456","77")<<endl;
    cout<<obj->addStrings("0","0")<<endl;
    return 0;
}