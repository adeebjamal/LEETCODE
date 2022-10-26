#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(string& domain: cpdomains) {
            domain.push_back('.');
            string num="", temp="";
            vector<string> words;
            for(char& letter: domain) {
                if(letter>='0' and letter<='9') {
                    num.push_back(letter);
                }
                else if(letter != '.') {
                    temp.push_back(letter);
                }
                else if(letter=='.') {
                    words.push_back(temp);
                    temp="";
                }
            }
            int number=stoi(num);
            int len=words.size();
            for(int i=0; i<len; i++) {
                string temporary="";
                for(int j=i; j<len; j++) {
                    if(words[j][0]==' ') {
                        words[j].erase(0,1);
                    }
                    if(words[j].back()==' ') {
                        words[j].pop_back();
                    }
                    temporary+= words[j] + '.';
                }
                temporary.pop_back();
                mp[temporary]+= number;
            }
        }
        for(auto& it: mp) {
            ans.push_back(to_string(it.second) + ' ' + it.first);
        }
        return ans;
    }
};
int main() {
    Solution obj;
    vector<string> vec={"9001 discuss.leetcode.com"};
    for(string& word: obj.subdomainVisits(vec)) {
        cout<<word<<endl;
    }
    vec={"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    for(string& word: obj.subdomainVisits(vec)) {
        cout<<word<<endl;
    }
    return 0;
}