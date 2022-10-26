#include<bits/stdc++.h>
using namespace std;
int compress(vector<char>& chars) {
    char prev=chars[0];
    int curr_co=0, n=chars.size();
    vector<char> ans;
    for(int i=0; i<n; i++) {
        if(prev==chars[i]) {
            curr_co++;
        }
        else {
            ans.push_back(prev);
            if(curr_co>1) {
                while(curr_co) {
                    ans.push_back((char)(curr_co%10));
                }
            }
            prev=chars[i];
            curr_co=0;
        }
    }
    return ans.size();
}
int main() {
    vector<char> chars={'a','a','b','b','c','c','c'};
    cout<<compress(chars)<<endl;
    return 0;
}