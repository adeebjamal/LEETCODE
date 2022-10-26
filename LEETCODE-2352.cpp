#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> cols;
        int col=grid[0].size();
        for(int i=0; i<col; i++) {
            vector<int> column;
            for(vector<int>& row: grid) {
                column.push_back(row[i]);
            }
            cols.push_back(column);
        }
        int ans=0;
        for(vector<int>& row: grid) {
            for(vector<int>& column: cols) {
                if(row==column) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> mat1={{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    vector<vector<int>> mat2={{3,2,1},{1,7,6},{2,7,7}};
    Solution ob;
    cout<<ob.equalPairs(mat1)<<endl;
    cout<<ob.equalPairs(mat2)<<endl;
    return 0;
}