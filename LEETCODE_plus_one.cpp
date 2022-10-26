#include<bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
    int power=digits.size()-1;
    long long int sum=0;
    for(int i: digits) {
        sum=sum+i*pow(10,power--);
    }
    digits.clear();
    sum+=1;
    while(sum != 0) {
        digits.push_back(sum%10);
        sum=sum/10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}
int main() {
    vector<int> input={1,2,3,4,5};
    vector<int> output=plusOne(input);
    for(int i: output) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}