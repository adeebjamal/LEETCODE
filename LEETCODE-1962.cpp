#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int& pile: piles) {
            pq.push(pile);
        }
        while(k--) {
            int top=pq.top();
            pq.pop();
            top-= top/2;
            if(top>0) {
                pq.push(top);
            }
        }
        int sum=0;
        while(!pq.empty()) {
            sum+= pq.top();
            pq.pop();
        }
        return sum;
    }
};
int main() {
    return 0;
}