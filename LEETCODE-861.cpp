#include<bits/stdc++.h>
using namespace std;
int matrixScore(vector<vector<int>> grid) {
    int sum=0;
    for(vector<int>& row: grid) {
        if(row[0]==0) {
            for(int& bit: row) {
                if(bit==0) {
                    bit=1;
                }
                else {
                    bit=0;
                }
            }
        }
    }
    int col=grid[0].size();
    for(int i=0; i<col; i++) {
        unordered_map<int,int> mp;
        for(vector<int>& row: grid) {
            mp[row[i]]++;
        }
        if(mp[0]>mp[1]) {
            for(vector<int>& row: grid) {
                if(row[i]==0) {
                    row[i]=1;
                }
                else {
                    row[i]=0;
                }
            }
        }
    }
    int exponent=grid[0].size()-1;
    for(vector<int>& row: grid) {
        int power=exponent;
        for(int& bit: row) {
            sum+= bit*pow(2,power--);
        }
    }
    return sum;
}
int main() {
    vector<vector<int>> grid={{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout<<matrixScore(grid)<<endl;
    cout<<matrixScore({{0}})<<endl;
    return 0;
}