// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,-1,0,1};
    void dfs(int row, int col, vector<vector<bool>>& vis, vector<vector<int>>& grid, vector<pair<int,int>>& vec, int& br, int& bc) {
        vis[row][col] = true;
        vec.push_back({row-br,col-bc});
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<4; i++) {
            int nrow = row + this->dr[i], ncol = col + this->dc[i];
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m) {
                if(vis[nrow][ncol] == false and grid[nrow][ncol] == 1) {
                    dfs(nrow,ncol,vis,grid,vec,br,bc);
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        set<vector<pair<int,int>>> st;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] == false and grid[i][j] == 1) {
                    vector<pair<int,int>> vec;
                    this->dfs(i,j,vis,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
int main() {
    Solution* obj = new Solution();
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},{1, 1, 0, 0, 0},{0, 0, 0, 1, 1},{0, 0, 0, 1, 1}};
    cout<<obj->countDistinctIslands(grid)<<endl;
    return 0;
}