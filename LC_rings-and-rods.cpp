#include<bits/stdc++.h>
using namespace std;
int countPoints(string& rings) {
    unordered_map<int, unordered_set<char>> m;
    while(rings.length()) {
        char color=rings[0];
        int rod=rings[1] - '0';
        m[rod].insert(color);
        rings.erase(0,2);
    }
    int ans=0;
    for(auto it=m.begin(); it != m.end(); it++) {
        if((it->second).size()==3) {
            ans++;
        }
    }
    return ans;
}
int main() {
    string rings="B0R0G0R9R0B0G0";
    cout<<countPoints(rings)<<endl;
    return 0;
}