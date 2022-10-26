#include<bits/stdc++.h>
using namespace std;
int sum4divisors(vector<int>& nums) {
    unordered_map<int,int> m; //<element, frequency>
    long long int sum=0;
    for(int i=0; i<nums.size(); i++) {
        m.insert({nums[i], count(nums.begin(), nums.end(),nums[i])});
    }
    for(auto it=m.begin(); it!=m.end(); it++) {
        vector<int> factor={1,it->first};
        for(int j=2; j<=sqrt(it->first); j++) {
            if(j==sqrt(it->first) && (it->first)%j==0) {
                factor.push_back(j);
                continue;
            }
            if((it->first)%j==0) {
                factor.push_back(j);
                factor.push_back((it->first)/j);
            }
        }
        if(factor.size()==4) {
            sum+=(it->second)*(accumulate(factor.begin(),factor.end(),0));
        }
    }
    return sum;
}
int main() {
    vector<int> v={21,21,7,3};
    cout<<sum4divisors(v)<<endl;
    return 0;
}