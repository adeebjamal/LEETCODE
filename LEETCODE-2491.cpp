#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long int answer=0;
        int start=0, end=skill.size()-1;
        while(start<end) {
            if(skill[start]+skill[end] != skill.front()+skill.back()) {
                return -1LL;
            }
            answer+= (skill[start++]*skill[end--]);
        }
        return answer;
    }
};
int main() {
    Solution* obj;
    vector<int> skill={3,2,5,1,3,4};
    cout<<obj->dividePlayers(skill)<<endl;
    skill={1,1,2,3};
    cout<<obj->dividePlayers(skill)<<endl;
    skill={3,4};
    cout<<obj->dividePlayers(skill);
    return 0;
}