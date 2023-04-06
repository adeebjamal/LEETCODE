#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(vector<int>& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int nodes = adj.size();
        for(auto& itr: adj) {
            if(itr.second.size() == nodes - 1) {
                return itr.first;
            }
        }
        return -1;
    }
};
int main() {
    Solution* obj = new Solution();
    vector<vector<int>> edges = {{1,2},{2,3},{4,2}};
    cout<<obj->findCenter(edges)<<endl;
    edges = {{1,2},{5,1},{1,3},{1,4}};
    cout<<obj->findCenter(edges)<<endl;
    return 0;
}