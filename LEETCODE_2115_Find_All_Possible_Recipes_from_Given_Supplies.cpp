#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        unordered_set<string> recipySet;
        for(int i = 0; i < recipes.size(); i++) {
            for(string& ingredient: ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
            }
            indegree[recipes[i]] = ingredients[i].size();
            recipySet.insert(recipes[i]);
        }
        queue<string> q;
        for(string& supply: supplies) {
            q.push(supply);
        }
        vector<string> answer;
        while(!q.empty()) {
            string node = q.front();
            q.pop();
            if(recipySet.find(node) != recipySet.end()) {
                answer.push_back(node);
            }
            for(string& neighbour: graph[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        return answer;
    }
};