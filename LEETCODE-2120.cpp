#include<bits/stdc++.h>
using namespace std;
int result(int& n, int row, int col, string& s, int& len, int start) {
    int ans=0;
    for(int i=start; i<len; i++) {
        if(s[i]=='L') {
            col--;
        }
        else if(s[i]=='R') {
            col++;
        }
        else if(s[i]=='U') {
            row--;
        }
        else if(s[i]=='D') {
            row++;
        }
        if(row<0 || col<0 || row>=n || col>=n) {
            return ans;
        }
        ans++;
    }
    return ans;
}
vector<int> executeInstructions(int& n, vector<int>& startPos, string& s) {
    int len=s.length();
    vector<int> ans(len,0);
    for(int i=0; i<len; i++) {
        ans[i]=result(n,startPos[0],startPos[1],s,len,i);
    }
    return ans;
}
int main() {
    int n=1;
    vector<int> startPos={0,0};
    string s="LRUD";
    vector<int> ans=executeInstructions(n,startPos,s);
    for(int& i: ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}