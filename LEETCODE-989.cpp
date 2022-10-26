#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int end=num.size()-1, sum=0;
        vector<int> ans;
        while(end>=0 or k!=0 or sum>0) {
            if(end>=0) {
                sum+=num[end--];
            }
            if(k!=0) {
                sum+=k%10;
                k/=10;
            }
            ans.push_back(sum%10);
            sum/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main() {
    vector<int> num={1,2,0,0};
    Solution* obj;
    for(int& digit: obj->addToArrayForm(num,34)) {
        cout<<digit<<" ";
    }
    cout<<endl;
    num={2,7,4};
    for(int& digit: obj->addToArrayForm(num,181)) {
        cout<<digit<<" ";
    }
    cout<<endl;
    num={9,9,9};
    for(int& digit: obj->addToArrayForm(num,1)) {
        cout<<digit<<" ";
    }
    cout<<endl;
    num={0};
    for(int& digit: obj->addToArrayForm(num,23)) {
        cout<<digit<<" ";
    }
    cout<<endl;
    num={7};
    for(int& digit: obj->addToArrayForm(num,993)) {
        cout<<digit<<" ";
    }
    cout<<endl;
    return 0;
}