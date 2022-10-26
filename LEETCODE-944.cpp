#include<bits/stdc++.h>
using namespace std;
int minDeletionSize(vector<string>& strs) {
    int row=strs.size(), col=strs[0].length(), ans=0;
    for(int i=0; i<col; i++) {
        for(int j=0; j<row-1; j++) {
            if(strs[j][i]>strs[j+1][i]) {
                ans++;
                break;
            }
        }
    }
    return ans;
}
int main() {
    vector<string> strs1={"cba","daf","ghi"};
    vector<string> strs2={"a","b"};
    vector<string> strs3={"zyx","wvu","tsr"};
    cout<<minDeletionSize(strs1)<<endl;
    cout<<minDeletionSize(strs2)<<endl;
    cout<<minDeletionSize(strs3)<<endl;
    return 0;
}