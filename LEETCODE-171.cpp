#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(char& letter: columnTitle) {
            ans = ans*26 + (letter-'A'+1);
        }
        return ans;
    }
};
int main() {
    Solution *obj;
    cout<<obj->titleToNumber("A")<<endl;
    cout<<obj->titleToNumber("AB")<<endl;
    cout<<obj->titleToNumber("ZY")<<endl;
    //cout<<obj->titleToNumber("A")<<endl;
    return 0;
}