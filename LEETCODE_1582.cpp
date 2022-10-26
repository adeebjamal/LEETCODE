#include<bits/stdc++.h>
using namespace std;
int numSpecial(vector<vector<int>>& mat) {
    int ans=0, row=mat.size(), col=mat[0].size();
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(mat[i][j]==1) {
                unordered_map<int,int> mp1;
                for(int k=0; k<col; k++) {
                    mp1[mat[i][k]]++;
                }
                unordered_map<int,int> mp2;
                for(int k=0; k<row; k++) {
                    mp2[mat[k][j]]++;
                }
                if(mp1[1]==1 && mp2[1]==1) {
                    ans++;
                }
            }
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> mat1={{1,0,0},{0,0,1},{1,0,0}};
    cout<<numSpecial(mat1)<<endl;
    vector<vector<int>> mat2={{1,0,0},{0,1,0},{0,0,1}};
    cout<<numSpecial(mat2)<<endl;
    return 0;
}