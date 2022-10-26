#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void BFS(vector<vector<int>>& rooms, vector<int>& visited) {
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            for(int& key: rooms[q.front()]) {
                if(visited[key]==0) {
                    q.push(key);
                    visited[key]=1;
                }
            }
            q.pop();
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int number_of_rooms=rooms.size();
        vector<int> visited(number_of_rooms,0);
        visited[0]=1;
        BFS(rooms,visited);
        return count(visited.begin(),visited.end(),1)==number_of_rooms;
    }
};
int main() {
    return 0;
}