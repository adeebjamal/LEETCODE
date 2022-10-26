#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber) {
            ans.push_back((columnNumber % 26) + 'A' );
            columnNumber/=26;
        }
        return ans;
    }
};
int main() {
    Solution* obj;
    cout<<obj->convertToTitle(1)<<endl;
    cout<<obj->convertToTitle(28)<<endl;
    cout<<obj->convertToTitle(701)<<endl;
    return 0;
}