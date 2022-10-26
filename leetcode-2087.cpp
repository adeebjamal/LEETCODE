#include<bits/stdc++.h>
using namespace std;
int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    int startRow=startPos[0], startCol=startPos[1];
    int homeRow=homePos[0], homeCol=homePos[1];
    int cost=0;
    if(homeRow>=startRow) {
        for(int r=startRow+1; r<=homeRow; r++) {
            cost+= rowCosts[r];
        }
    }
    else {
        for(int r=startRow-1; r>=homeRow; r--) {
            cost+= rowCosts[r];
        }
    }
    if(homeCol>=startCol) {
        for(int c=startCol+1; c<=homeCol; c++) {
            cost+= colCosts[c];
        }
    }
    else {
        for(int c=startCol-1; c>=homeCol; c--) {
            cost+= colCosts[c];
        }
    }
    return cost;
}
int main() {
    vector<int> startPos={1,0};
    vector<int> homePos={2,3};
    vector<int> rowCost={5,4,3};
    vector<int> colCost={8,2,6,7};
    cout<<minCost(startPos,homePos,rowCost,colCost)<<endl;
    return 0;
}