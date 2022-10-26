#include<bits/stdc++.h>
using namespace std;
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int rows=mat.size(), cols=mat[0].size();
    for(vector<int>& row: mat) {
        row.push_back(-1);
        row.insert(row.begin(),-1);
    }
    vector<int> help(cols+2,-1);
    mat.insert(mat.begin(),help);
    mat.push_back(help);
    rows=mat.size(), cols=mat[0].size();
    for(int i=1; i<rows-1; i++) {
        for(int j=1; j<cols-1; j++) {
            if(mat[i][j]>mat[i+1][j]) {
                if(mat[i][j]>mat[i][j+1]) {
                    if(mat[i][j]>mat[i-1][j]) {
                        if(mat[i][j]>mat[i][j-1]) {
                            return {i-1,j-1};
                        }
                    }
                }
            }
        }
    }
    return {};
}
int main() {
    vector<vector<int>> mat={{10,20,15},{21,30,14},{7,16,32}};
    vector<int> ans=findPeakGrid(mat);
    for(int& i: ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}