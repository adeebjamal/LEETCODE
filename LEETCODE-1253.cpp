#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> reconstructMatrix(int& upper, int& lower, vector<int>& colsum) {
    int len=colsum.size();
    vector<int> top(len,0);
    vector<int> bottom(len,0);
    for(int i=0; i<len; i++) {
        if(colsum[i]==2) {
            top[i]=1;
            upper--;
            bottom[i]=1;
            lower--;
        }
        else if(colsum[i]==1) {
            if(upper>lower) {
                top[i]=1;
                upper--;
            }
            else {
                bottom[i]=1;
                lower--;
            }
        }
    }
    if(upper != 0 || lower != 0) {
        return {};
    }
    return {top,bottom};
}
int main() {
    vector<int> colsum={2,1,2,0,1,0,1,2,0,1};
    int upper=5, lower=5;
    vector<vector<int>> mat=reconstructMatrix(upper,lower,colsum);
    for(vector<int>& row: mat) {
        for(int& i: row) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}