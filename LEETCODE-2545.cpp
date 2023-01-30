#include<bits/stdc++.h>
using namespace std;
bool comparator(vector<int>& a, vector<int>& b, int& index) {
    return a[index] < b[index];
}
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        for(int i=0; i<score.size()-1; i++) {
            for(int j=0; j<score.size()-i-1; j++) {
                if(comparator(score[j],score[j+1],k)) {
                    swap(score[j],score[j+1]);
                }
            }
        }
        return score;
    }
};
int main() {
    Solution* obj;
    vector<vector<int>> score={{10,6,9,1},{7,5,11,2},{4,8,3,15}};
    obj->sortTheStudents(score,2);
    for(vector<int>& row: score) {
        for(int& num: row) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}