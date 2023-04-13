// https://leetcode.com/problems/find-the-town-judge/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>> adj, adj2;
        for(vector<int>& row: trust) {
            adj[row[1]].push_back(row[0]);
            adj2[row[0]].push_back(row[1]);
        }
        for(int person=1; person<=n; person++) {
            if(adj[person].size() == n-1 and adj2[person].size() == 0) {
                return person;
            }
        }
        return -1;
    }
};