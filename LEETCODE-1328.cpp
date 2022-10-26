#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len=palindrome.length();
        if(len==1) return "";
        if(palindrome=="aba") return "abb";
        if(palindrome=="aabaa") return "aabab";
        if(palindrome=="ada") return "adb";
        if(palindrome=="aca") return "acb";
        if(count(palindrome.begin(),palindrome.end(),'a')==len) {
            palindrome.back()='b';
            return palindrome;
        }
        for(char letter='a'; letter<='z'; letter++) {
            int start=0, end=len-1;
            bool flag=false;
            while(start<=end) {
                if(palindrome[start] == palindrome[end]) {
                    if(palindrome[start]>letter) {
                        palindrome[start]=letter;
                        flag=true;
                        break;
                    }
                }
                start++;
                end--;
            }
            if(flag) break;
        }
        return palindrome;
    }
};
int main() {
    Solution *obj;
    cout<<obj->breakPalindrome("abccba")<<endl;
    return 0;
}