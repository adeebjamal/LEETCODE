#include<bits/stdc++.h>
using namespace std;
string findDifferentBinaryString(vector<string>& nums) {
    unordered_map<int,int> mp;
    for(string& num: nums) {
        int power=num.length()-1;
        int sum=0;
        for(char& bit: num) {
            sum+= (bit-'0')*pow(2,power--);
        }
        mp[sum]++;
    }
    int range=pow(2,nums[0].length())-1;
    int missing=0;
    for(int i=0; i<=range; i++) {
        if(mp[i]==0) {
            missing=i;
            break;
        }
    }
    string binary="";
    while(missing) {
        binary.push_back((missing % 2) + '0');
        missing/=2;
    }
    int gap=nums[0].length() - binary.length();
    while(gap--) {
        binary.push_back('0');
    }
    reverse(binary.begin(),binary.end());
    return binary;
}
int main() {
    vector<string> nums={"01","10"};
    string ans=findDifferentBinaryString(nums);
    for(string& num: nums) {
        cout<<num<<" ";
    }
    cout<<endl<<ans<<endl;
    return 0;
}