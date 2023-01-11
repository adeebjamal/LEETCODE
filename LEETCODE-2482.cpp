#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<pair<int,int>> r, c;     // <zero,one>
        for(vector<int>& row: grid) {
            int zero=0, one=0;
            for(int& num: row) {
                if(num==0) zero++;
                else one++;
            }
            r.push_back({zero,one});
        }
        for(int col=0; col<grid[0].size(); col++) {
            int zero=0, one=0;
            for(vector<int>& row: grid) {
                if(row[col]==0) zero++;
                else one++;
            }
            c.push_back({zero,one});
        }
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                int res=r[i].second + c[j].second - r[i].first - c[j].first;
                grid[i][j] = res;
            }
        }
        return grid;
    }
};
int main() {
    Solution* obj;
    vector<vector<int>> mat = {{0,1,1},{1,0,1},{0,0,1}};
    for(vector<int>& row: obj->onesMinusZeros(mat)) {
        for(int& num: row) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    mat = {{1,1,1},{1,1,1}};
    for(vector<int>& row: obj->onesMinusZeros(mat)) {
        for(int& num: row) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}