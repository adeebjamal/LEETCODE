#include<bits/stdc++.h>
using namespace std;
class Solution {
    string bfs(char& src, char& des, unordered_map<char, bool>& visited, unordered_map<char, string>& graph) {
        queue<char> q;
        q.push(src);
        visited[src] = true;
        while(q.empty() == false) {
            char node = q.front();
            if(node == des) {
                return "equal";
            }
            q.pop();
            for(char& neighbour: graph[node]) {
                if(visited[neighbour] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return "unequal";
    }
    public:
    bool equationsPossible(vector<string>& equations) {
        set<pair<char, char>> edges;
        for(string& eqn: equations) {
            if(eqn[1] == '=') {
                edges.insert({eqn[0], eqn[3]});
            }
        }
        unordered_map<char, string> graph;
        for(auto itr = edges.begin(); itr != edges.end(); itr++) {
            pair<char, char> edge = *itr;
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
        for(string& eqn: equations) {
            char u = eqn[0], v = eqn[3];
            unordered_map<char, bool> visited;
            if(eqn[1] == '=') {
                if(this->bfs(u, v, visited, graph) == "unequal") {
                    return false;
                }
            }
            else if(eqn[1] == '!') {
                if(this->bfs(u, v, visited, graph) == "equal") {
                    return false;
                }
            }
        }
        return true;
    }
};