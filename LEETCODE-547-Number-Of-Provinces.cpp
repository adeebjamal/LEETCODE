#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void bfs(int& source, vector<vector<int>>& graph, vector<bool>& vis) {
        queue<int> q;
        q.push(source);
        vis[source] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int i=0; i<graph[node].size(); i++) {
                if(graph[node][i] == 1 and vis[i] == false) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);
        int answer = 0;
        for(int i=0; i<n; i++) {
            if(vis[i] == false) {
                answer++;
                this->bfs(i,isConnected,vis);
            }
        }
        return answer;
    }
};