#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<int,vector<int>> mp;      // <index,{metal,paper,glass}>
        int total_metal=0, total_paper=0, total_glass=0;
        for(int index=0; index<garbage.size(); index++) {
            int metal=0, paper=0, glass=0;
            for(char& letter: garbage[index]) {
                metal+= (letter=='M');
                paper+= (letter=='P');
                glass+= (letter=='G');
            }
            mp[index]={metal,paper,glass};
            total_metal+= metal;
            total_paper+= paper;
            total_glass+= glass;
        }
        int time=0;
        // metal truck
        for(int index=0; index<garbage.size() and total_metal>0; index++) {
            time+= mp[index][0];
            total_metal-= mp[index][0];
            if(total_metal>0) {
                time+= travel[index];
            }
        }
        // paper truck
        for(int index=0; index<garbage.size() and total_paper>0; index++) {
            time+= mp[index][1];
            total_paper-= mp[index][1];
            if(total_paper>0) {
                time+= travel[index];
            }
        }
        // glass truck
        for(int index=0; index<garbage.size(); index++) {
            time+= mp[index][2];
            total_glass-= mp[index][2];
            if(total_glass>0) {
                time+= travel[index];
            }
        }
        return time;
    }
};
int main() {
    Solution* obj;
    vector<string> garbage={"G","P","GP","GG"};
    vector<int> travel={2,4,3};
    cout<<obj->garbageCollection(garbage,travel)<<endl;
    garbage={"MMM","PGM","GP"};
    travel={3,10};
    cout<<obj->garbageCollection(garbage,travel);
    return 0;
}