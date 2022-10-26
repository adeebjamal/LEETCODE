#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int,int>>> vec;
        int len=arr.size();
        for(int i=0; i<len; i++) {
            for(int j=0; j<len; j++) {
                double ratio= (arr[i]*1.0)/(arr[j]*1.0);
                vec.push_back({ratio, {arr[i],arr[j]}});
            }
        }
        sort(vec.begin(),vec.end());
        pair<int,int> ans= vec[k-1].second;
        return {ans.first, ans.second};
    }
};
int main() {

    return 0;
}