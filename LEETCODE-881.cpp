#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:

//     -------------- WRONG --------------

//     int numRescueBoats(vector<int>& people, int limit) {
//         priority_queue<int> pq(people.begin(),people.end());
//         int answer = 0;
//         while(!pq.empty()) {
//             int first = 0, second = 0;
//             if(!pq.empty()) {
//                 first = pq.top();
//                 pq.pop();
//             }
//             if(!pq.empty()) {
//                 second = pq.top();
//                 pq.pop();
//             }
//             if(first + second <= limit) {
//                 answer++;
//             }
//             else if(first <= limit) {
//                 pq.push(second);
//                 answer++;
//             }
//         }
//         return answer;
//     }
// };
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int start = 0, end = people.size()-1, answer = 0;
        while(start <= end) {
            if(people[start] + people[end] <= limit) {
                answer++;
                start++;
                end--;
            }
            else {
                answer++;
                end--;
            }
        }
        return answer;
    }
};
int main() {
    Solution* obj;
    vector<int> nums = {1,2};
    cout<<obj->numRescueBoats(nums,3)<<endl;
    nums = {3,2,2,1};
    cout<<obj->numRescueBoats(nums,3)<<endl;
    nums = {3,5,3,4};
    cout<<obj->numRescueBoats(nums,5)<<endl;
    return 0;
}