#include<bits/stdc++.h>
using namespace std;
class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
        for(int seat=1; seat<=n; seat++) {
            pq.push(seat);
        }
    }
    
    int reserve() {
        int seat=pq.top();
        pq.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};