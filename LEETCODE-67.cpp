#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int end1=a.length()-1, end2=b.length()-1, carry=0;
        while(end1>=0 or end2>=0 or carry) {
            if(end1>=0) {
                carry+= a[end1--]-'0';
            }
            if(end2>=0) {
                carry+= b[end2--]-'0';
            }
            ans.push_back(carry%2 + '0');
            carry/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main() {
    Solution *obj;
    cout<<obj->addBinary("11","1")<<endl;
    cout<<obj->addBinary("1010","1011")<<endl;
    return 0;
}