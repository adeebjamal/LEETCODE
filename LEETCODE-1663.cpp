#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        for(int i=0; i<n; i++) {
            ans.push_back('a');
        }
        k-=n;
        int end=n-1;
        while(end>=0 and k>0) {
            if(k>25) {
                ans[end--]='z';
                k-=25;
            }
            else {
                ans[end--]='a'+k;
                k=0;
            }
        }
        return ans;
    }
};
int main() {
    Solution* obj;
    cout<<obj->getSmallestString(3,27)<<endl;
    cout<<obj->getSmallestString(5,73)<<endl;
    cout<<obj->getSmallestString(10,250)<<endl;
    cout<<obj->getSmallestString(9,100)<<endl;
    return 0;
}