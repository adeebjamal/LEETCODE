// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
#include <bits/stdc++.h>
using namespace std;
vector<int> gradingStudents(vector<int>& grades) {
    for(int& grade: grades) {
        if(grade < 38) {
            continue;
        }
        for(int num=grade; ; num++) {
            if(num%5 == 0) {
                if(num - grade < 3) {
                    grade = num;
                }
                break;
            }
        }
    }
    return grades;
}
int main() {
    int len=0;
    cin>>len;
    vector<int> nums;
    for(int i=0; i<len; i++) {
        int x=0;
        cin>>x;
        nums.push_back(x);
    }
    for(int& grade: gradingStudents(nums)) {
        cout<<grade<<endl;
    }
    return 0;
}