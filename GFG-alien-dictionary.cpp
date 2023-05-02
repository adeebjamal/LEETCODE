#include<bits/stdc++.h>
using namespace std;
class Solution{
    stack<char> st;
    void dfs(char node, unordered_map<char,bool>& vis, unordered_map<char,vector<char>>& adj) {
        vis[node] = true;
        for(char& neighbour: adj[node]) {
            if(vis[neighbour] == false) {
                this->dfs(neighbour,vis,adj);
            }
        }
        this->st.push(node);
    }
    public:
    string findOrder(string dict[], int N, int K) {
        unordered_map<char,vector<char>> adj;
        for(int i=0; i<N-1; i++) {
            int len = min(dict[i].length(),dict[i+1].length());
            for(int j=0; j<len; j++) {
                if(dict[i][j] != dict[i+1][j]) {
                    adj[dict[i][j]].push_back(dict[i+1][j]);
                    break;
                }
            }
        }
        unordered_map<char,bool> vis;
        for(char letter = 'a'; letter<'a'+K; letter++) {
            if(vis[letter] == false) {
                this->dfs(letter,vis,adj);
            }
        }
        string answer = "";
        while(!this->st.empty()) {
            answer.push_back(this->st.top());
            this->st.pop();
        }
        if(answer.length() != K) {
            return "";
        }
        return answer;
    }
};
int main() {
    Solution* obj = new Solution();
    string dict[5] = {"baa","abcd","abca","cab","cad"};
    cout<<obj->findOrder(dict,5,4)<<endl;
    return 0;
}