#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool bfs(int& source, int& destination, unordered_map<int,bool>& visited, unordered_map<int,vector<int>>& graph) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()) {
            int node = q.front();
            if(node == destination) {
                return true;
            }
            q.pop();
            for(int& neighbour: graph[node]) {
                if(visited[neighbour] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> graph;
        for(vector<int>& vec: prerequisites) {
            graph[vec[0]].push_back(vec[1]);
        }
        vector<bool> answer;
        for(vector<int>& query: queries) {
            unordered_map<int,bool> visited;
            answer.push_back(this->bfs(query[0], query[1], visited, graph));
        }
        return answer;
    }
};