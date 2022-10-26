#include<bits/stdc++.h>
using namespace std;
bool perfectSquare(int b) {
    float f= sqrt(b);
    int i= sqrt(b);
    return (i==f);
}
bool judgeSquareSum(int c) {
    if(perfectSquare(c)) {
        return true;
    }
    for(int i=0; i*i<=c; i++) {
        int a= c-i*i;
        if(perfectSquare(a)) {
            return true;
        }
    }
    return false;
}
int main() {
    cout<<judgeSquareSum(999999999)<<endl;
    return 0;
}