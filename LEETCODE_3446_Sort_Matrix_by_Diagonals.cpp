#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
            unordered_map<int, deque<int>> hash;
            int n = grid.size();
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    hash[i - j].push_back(grid[i][j]);
                }
            }
    
            for(auto& itr: hash) {
                if(itr.first >= 0) {
                    sort(itr.second.rbegin(), itr.second.rend());
                }
                else {
                    sort(itr.second.begin(), itr.second.end());
                }
            }
    
            // vector<vector<int>> answer(n, vector<int>(n, -1));
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    grid[i][j] = hash[i - j].front();
                    hash[i - j].pop_front();
                }
            }
    
            return grid;
        }
    };