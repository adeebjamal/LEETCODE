#include<bits/stdc++.h>
using namespace std;
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,pair<int,vector<int>>> graph;
        for(Employee* emp: employees) {
            graph[emp->id].first = emp->importance;
            graph[emp->id].second = emp->subordinates;
        }
        unordered_map<int,int> visited;
        int answer = 0;
        queue<int> q;
        q.push(id);
        visited[id] = 1;
        while(!q.empty()) {
            int frontEmp = q.front();
            q.pop();
            answer+= graph[frontEmp].first;
            for(int& empID: graph[frontEmp].second) {
                if(visited[empID] == 0) {
                    q.push(empID);
                    visited[empID] = 1;
                }
            }
        }
        return answer;
    }
};