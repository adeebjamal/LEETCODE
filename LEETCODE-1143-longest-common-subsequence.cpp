#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string str1="", str2="";
    int solve(int index1, int index2, vector<vector<int>>& dp) {
        if(index1<0 or index2<0) {
            return 0;
        }
        if(dp[index1][index2] != -1) {
            return dp[index1][index2];
        }
        if(str1[index1] == str2[index2]) {
            return dp[index1][index2] = 1 + solve(index1-1, index2-1, dp);
        }
        return dp[index1][index2] = max(solve(index1-1,index2,dp),solve(index1,index2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        str1=text1;
        str2=text2;
        int len1=text1.length(), len2=text2.length();
        vector<vector<int>> dp(len1, vector<int>(len2,-1));
        return solve(len1-1, len2-1, dp);
    }
};
int main() {
    Solution* obj;
    cout<<obj->longestCommonSubsequence("abcde","ace")<<endl;
    cout<<obj->longestCommonSubsequence("abc","abc")<<endl;
    cout<<obj->longestCommonSubsequence("abc","def");
    return 0;
}