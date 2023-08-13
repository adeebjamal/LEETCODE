#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> graph;
        for(int i=0; i<manager.size(); i++) {
            if(manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }
        vector<bool> visited(n,false);
        queue<pair<int,int>> q;
        q.push({headID,0});
        visited[headID] = true;
        int answer = 0;
        while(!q.empty()) {
            int manager = q.front().first, time = q.front().second;
            q.pop();
            answer = max(answer,time);
            for(int& subOrdinate: graph[manager]) {
                if(visited[subOrdinate] == false) {
                    q.push({subOrdinate,time+informTime[manager]});
                    visited[subOrdinate] = true;
                }
            }
        }
        return answer;
    }
};