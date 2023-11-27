#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(string& source, string& destination, double& answer, double product, unordered_map<string,vector<pair<string,double>>>& graph, unordered_set<string>& visited) {
        if(source == destination) {
            answer = product;
            return;
        }
        visited.insert(source);
        for(pair<string,double>& edge: graph[source]) {
            if(visited.find(edge.first) == visited.end()) {
                this->dfs(edge.first, destination, answer, product * edge.second, graph, visited);
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> graph;
        unordered_map<string,int> hash;
        int index = 0;
        for(vector<string>& edge: equations) {
            graph[edge[0]].push_back({edge[1], values[index]});
            graph[edge[1]].push_back({edge[0], 1.0/values[index]});
            hash[edge[0]]++;
            hash[edge[1]]++;
            index++;
        }
        vector<double> answer;
        for(vector<string>& query: queries) {
            if(hash[query[0]] == 0 or hash[query[1]] == 0) {
                answer.push_back(-1.00000);
                continue;
            }
            unordered_set<string> visited;
            double result = -1.00000, product = 1.00000;
            this->dfs(query[0], query[1], result, product, graph, visited);
            answer.push_back(result);
        }
        return answer;
    }
};