// Complement of base 10 integer
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n=0;
    cin>>n;
    deque<int> binary;
    if(n==0) {binary.push_front(n);}
    else {
        while(n!=0) {
            binary.push_front(n%2);
            n=n/2;
        }
    }
    for(int &i: binary) {
        if(i==1) {i=0;}
        else {i=1;}
    }
    int sum=0, power=binary.size()-1;
    for(int i: binary) {
        sum=sum+i*pow(2,power--);
    }
    cout<<sum<<endl;
    return 0;
}