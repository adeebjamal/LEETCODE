#include<bits/stdc++.h>
using namespace std;
class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        return;
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        int start=0, end=mp[key].size()-1;
        while(start<=end) {
            int mid=((end-start)/2) + start;
            if(mp[key][mid].first==timestamp) {
                return mp[key][mid].second;
            }
            else if(mp[key][mid].first<timestamp) {
                start=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return end>=0 ? mp[key][end].second : "";
    }
};
int main() {
    return 0;
}