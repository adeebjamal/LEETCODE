#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int ans=0;
        while(true) {
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            if(first==0 || second==0) {
                break;
            }
            first--;
            second--;
            ans++;
            pq.push(first);
            pq.push(second);
        }
        return ans;
    }
};
int main() {
    Solution* obj;
    cout<<obj->maximumScore(2,4,6)<<endl;
    cout<<obj->maximumScore(4,4,8)<<endl;
    cout<<obj->maximumScore(1,8,8)<<endl;
    return 0;
}