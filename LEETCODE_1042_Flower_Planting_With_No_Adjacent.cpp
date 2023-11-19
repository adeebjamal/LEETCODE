#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int,vector<int>> graph;
        for(vector<int>& path: paths) {
            graph[path[0]-1].push_back(path[1]-1);
            graph[path[1]-1].push_back(path[0]-1);
        }
        vector<int> flower(n, -1);
        for(int garden = 0; garden < n; garden++) {
            unordered_map<int,bool> available;
            for(int& neighbour: graph[garden]) {
                if(flower[neighbour] != -1) {
                    available[flower[neighbour]] = true;
                }
            }
            for(int flower_option = 1; flower_option <= 4; flower_option++) {
                if(available[flower_option] == false) {
                    flower[garden] = flower_option;
                    break;
                }
            }
        }
        return flower;
    }
};