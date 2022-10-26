#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int len=intervals.size();
    if(len==1) {
        return intervals;
    }
    //sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    int j=0;
    for(int i=0; i<len; i++) {
        if(ans[j][1]>=intervals[i][0]) {
            ans[j][1]=max(ans[j][1],intervals[i][1]);
        }
        else {
            ans.push_back(intervals[i]);
            j++;
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans=merge(intervals);
    for(vector<int>& row: ans) {
        for(int& num: row) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}