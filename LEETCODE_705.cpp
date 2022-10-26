#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
void add(int key) {
    mp[key]++;
}
bool contains(int key) {
    if(mp[key]>0) {
        return true;
    }
    return false;
}
void remove(int key) {
    auto it=mp.find(key);
    if(it != mp.end()) {
        mp.erase(it);
    }
}
int main() {

    return 0;
}