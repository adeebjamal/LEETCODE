#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> vec(1001,0);
        for(vector<int>& trip: trips) {
            vec[trip[1]]+=trip[0];
            vec[trip[2]]-=trip[0];
        }
        int in_car=0;
        for(int& number: vec) {
            in_car+= number;
            if(in_car>capacity) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    vector<vector<int>> trips = {{3,3,7},{2,1,5}};
    Solution *obj;
    cout<<obj->carPooling(trips,4)<<endl;
    trips = {{2,1,5},{3,3,7}};
    cout<<obj->carPooling(trips,5)<<endl;
    return 0;
}