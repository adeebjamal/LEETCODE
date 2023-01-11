#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> primes;
    unordered_map<int,int> mp;
    vector<bool> SieveOfEratosthenes(int n) {
        vector<bool> primes(n+1, true);
        primes[0]=false, primes[1]=false;
        int root=sqrt(n);
        for(int i=2; i<=root; i++) {
            if(primes[i]==true) {
                for(int j=i*i; j<=n; j=j+i) {
                    primes[j]=false;
                }
            }
        }
        return primes;
    }
    int prime_factors(int num) {
        int result=0;
        for(int factor=2; factor<=num; factor++) {
            if(primes[factor]==true and num%factor==0 and mp[factor]==0) {
                result++;
                mp[factor]=1;
                //while(num%factor==0) {
                //    num/=factor;
                //}
            }
        }
        return result;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        primes=SieveOfEratosthenes(1000);
        int answer=0;
        for(int& num: nums) {
            if(primes[num]==true and mp[num]==0) {
                answer++;
                mp[num]=1;
            }
            else {
                answer+= prime_factors(num);
            }
        }
        return answer;
    }
};
int main() {
    vector<int> nums={2,4,3,7,10,6};
    Solution* obj;
    cout<<obj->distinctPrimeFactors(nums)<<endl;
    nums={2,4,8,16};
    cout<<obj->distinctPrimeFactors(nums);
    return 0;
}