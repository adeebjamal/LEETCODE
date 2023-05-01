#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(vector<int>& task: prerequisites) {
            adj[task[0]].push_back(task[1]);
        }
        unordered_map<int,int> indegree;
        for(int course=0; course<numCourses; course++) {
            for(int& it: adj[course]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int course=0; course<numCourses; course++) {
            if(indegree[course] == 0) {
                q.push(course);
            }
        }
        vector<int> topo;
        while(!q.empty()) {
            topo.push_back(q.front());
            for(int& neighbour: adj[q.front()]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
            q.pop();
        }
        return topo.size() == numCourses;
    }
};