#include<bits/stdc++.h>
using namespace std;
class Solution
{
    void dfs(int node, bool vis[], vector<int> adj[], stack<int>& st) {
        vis[node] = true;
        for(int& neighbour: adj[node]) {
            if(vis[neighbour] == false) {
                dfs(neighbour,vis,adj,st);
            }
        }
        st.push(node);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    bool vis[V] = {false};
        stack<int> st;
        for(int i=0; i<V; i++) {
            if(vis[i] == false) {
                this->dfs(i,vis,adj,st);
            }
        }
        vector<int> answer;
        while(!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }
        return answer;
	}
};