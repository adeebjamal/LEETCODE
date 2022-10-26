#include<bits/stdc++.h>
using namespace std;
vector<string> simplifiedFractions(int n) {
    if(n==1) {
        return {};
    }
    unordered_set<string> ans;
    for(int dino=2; dino<=n; dino++) {
        for(int nume=1; nume<dino; nume++) {
            int gcd= __gcd(nume,dino);
            ans.insert(to_string(nume/gcd) + "/" + to_string(dino/gcd));
        }
    }
    return vector<string> (ans.begin(),ans.end());
}
int main() {
    int n=0;
    cin>>n;
    for(string& fraction: simplifiedFractions(n)) {
        cout<<fraction<<endl;
    }
    return 0;
}