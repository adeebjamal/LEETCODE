// https://www.hackerrank.com/challenges/components-in-graph/problem?isFullScreen=true
#include<bits/stdc++.h>
using namespace std;
int bfs(int& source, unordered_map<int,vector<int>>& graph, vector<bool>& vis) {
    int count = 0;
    queue<int> q;
    q.push(source);
    vis[source] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for(int& neighbour: graph[node]) {
            if(vis[neighbour] == false) {
                q.push(neighbour);
                vis[neighbour] = true;
            }
        }
    }
    return count;
}
int main() {
    unordered_map<int,vector<int>> graph;
    int edges=0, start=INT_MAX, end=INT_MIN;
    cin>>edges;
    for(int i=0; i<edges; i++) {
        int a=0, b=0;
        cin>>a>>b;
        start = min(start, min(a,b));
        end = max(end, max(a,b));
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int mini = INT_MAX, maxi = INT_MIN;
    vector<bool> vis(end+1,false);
    for(int node=start; node<=end; node++) {
        if(vis[node] == false) {
            int res = bfs(node, graph, vis);
            if(res >= 2) {
                mini = min(mini,res);
            }
            maxi = max(maxi,res);
        }
    }
    cout<<mini<<" "<<maxi;
    return 0;
}