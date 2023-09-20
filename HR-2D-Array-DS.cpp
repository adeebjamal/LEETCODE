// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true&h_r=next-challenge&h_v=zen
#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[6][6], answer = INT_MIN;
    for(int i=0; i<6; i++) {
        for(int j=0; j<6; j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            int result = 0;
            result+= arr[i][j];
            result+= arr[i][j+1];
            result+= arr[i][j+2];
            result+= arr[i+1][j+1];
            result+= arr[i+2][j];
            result+= arr[i+2][j+1];
            result+= arr[i+2][j+2];
            answer = max(answer,result);
        }
    }
    cout<<answer;
    return 0;
}