#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> seive(int n) {
        vector<bool> primes(n+1, true);
        primes[0]=false, primes[1]=false;
        for(int i=2; i<=sqrt(n); i++) {
            if(primes[i]==true) {
                for(int j=i*i; j<=n; j=j+i) {
                    primes[j]=false;
                }
            }
        }
        return primes;
    }
    bool solve(int& n, vector<bool>& primes) {
        if(primes[n]==true) {
            return false;
        }
        int sum=0;
        bool result=false;
        for(int factor=2; factor<=n/2; factor++) {
            if(n%factor==0 and primes[factor]==true) {
                result=true;
                int temp=n;
                while(temp%factor==0) {
                    sum+=factor;
                    temp/=factor;
                }
            }
        }
        if(n==sum) {
            return false;
        }
        n=sum;
        return result;
    }
    int smallestValue(int n) {
        vector<bool> primes=seive(n);
        while(solve(n,primes)) {

        }
        return n;
    }
};
int main() {
    Solution* obj;
    cout<<obj->smallestValue(15)<<endl;
    cout<<obj->smallestValue(3)<<endl;
    cout<<obj->smallestValue(4);
    return 0;
}