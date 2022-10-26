#include<bits/stdc++.h>
using namespace std;
deque<int> d2b(int n) {
        deque<int> binary;
        while(n != 0) {
            binary.push_front(n%2);
            n=n/2;
        }
        return binary;
    }
    deque<int> complement(deque<int>& binary) {
        for(int &i: binary) {
            if(i==0) {i=1;}
            else {i=0;}
            return binary;
        }
    }
    int b2d(deque<int>& binary) {
        int num=0, exponent=0;
        for(int i=binary.size()-1; i>=0; i--) {
            num=num+binary[i]*pow(2,exponent++);
        }
        return num;
    }
    int bitwiseComplement(int n) {
        deque<int> binary=d2b(n);
        deque<int> flip=complement(binary);
        int ans=b2d(flip);
        return ans;
    }
int main() {
    cout<<bitwiseComplement(5)<<endl;
    return 0;
}