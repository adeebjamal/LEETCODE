#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int decimal(string& num) {
        int value = 0;
        for(char& bit: num) {
            value = value*2 + (bit - '0');
        }
        return value;
    }
    string binary(int num) {
        string value = "";
        while(num) {
            value.push_back((num % 2) + '0');
            num/= 2;
        }
        reverse(value.begin(), value.end());
        return value;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int,int> hash;
        for(string& num: nums) {
            int value = this->decimal(num);
            hash[value]++;
        }
        int maxi = pow(2, nums[0].length());
        string answer = "";
        for(int num = 0; num < maxi; num++) {
            if(hash[num] == 0) {
                answer = this->binary(num);
                break;
            }
        }
        if(answer.length() < nums[0].length()) {
            string result = "";
            for(int i = 0; i < nums[0].length() - answer.length(); i++) {
                result.push_back('0');
            }
            answer = result + answer;
        }
        return answer;
    }
};
int main() {
    Solution* obj = new Solution();
    vector<string> nums = {"01","10"};
    cout<<obj->findDifferentBinaryString(nums)<<endl<<endl;
    nums = {"00","01"};
    cout<<obj->findDifferentBinaryString(nums)<<endl<<endl;
    nums = {"111","011","001"};
    cout<<obj->findDifferentBinaryString(nums)<<endl;
    return 0;
}