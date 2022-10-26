#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ones;     // represents the index i for which boxes[i]==1
        int len=boxes.length();
        for(int i=0; i<len; i++) {
            if(boxes[i]=='1') {
                ones.push_back(i);
            }
        }
        vector<int> ans(len,0);
        for(int i=0; i<len; i++) {
            int curr_sum=0;
            for(int& index: ones) {
                curr_sum+= abs(i-index);
            }
            ans[i]=curr_sum;
        }
        return ans;
    }
};
int main() {
    Solution* obj;
    for(int& index: obj->minOperations("001011")) {
        cout<<index<<" ";
    }
    cout<<endl;
    for(int& index: obj->minOperations("110")) {
        cout<<index<<" ";
    }
    cout<<endl;
    return 0;
}