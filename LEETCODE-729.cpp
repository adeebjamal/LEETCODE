#include<bits/stdc++.h>
using namespace std;
class MyCalendar {
public:
    unordered_map<int,int> mp;   // <start,end>
    MyCalendar() {
        return;
    }
    
    bool book(int start, int end) {
        for(auto& it: mp) {
            if(!(start>=it.second or end<=it.first)) {
                return false;
            }
        }
        mp[start]=end;
        return true;
    }
};
int main() {
    MyCalendar obj;
    vector<vector<int>> vec={{10, 20}, {15, 25}, {20, 30}};
    for(vector<int>& date: vec) {
        cout<<obj.book(date[0],date[1])<<" ";
    }
    cout<<endl;
    return 0;
}