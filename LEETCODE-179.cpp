#include<bits/stdc++.h>
using namespace std;
bool compare(string a, string b) {
    return a+b > b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> new_nums;
        for(int& num: nums) new_nums.push_back(to_string(num));
        sort(new_nums.begin(),new_nums.end(),compare);
        string ans="";
        for(string& num: new_nums) ans+=num;
        return ans;
    }
};
int main() {
    vector<int> nums={3,30,34,5,9};
    Solution* obj;
    cout<<obj->largestNumber(nums)<<endl;
    return 0;
}