#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        vector<bool> visited(len,false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()) {
            int index = q.front();
            if(arr[index] == 0) {
                return true;
            }
            q.pop();
            int index1 = index - arr[index], index2 = index + arr[index];
            if(index1 >= 0 and index1 < len) {
                if(visited[index1] == false) {
                    q.push(index1);
                    visited[index1] = true;
                }
            }
            if(index2 >= 0 and index2 < len) {
                if(visited[index2] == false) {
                    q.push(index2);
                    visited[index2] = true;
                }
            }
        }
        return false;
    }
};