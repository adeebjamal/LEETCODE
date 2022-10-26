#include<bits/stdc++.h>
using namespace std;
class FoodRatings {
public:
    unordered_map<string,vector<string>> mp;   // cuisine, list of dishes falling in that cuisine category
    unordered_map<string,int> ump;    // food, rating
    unordered_map<string,int> max_rating;
    unordered_map<string,string> fc; // food,cuisine
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int len=foods.size();
        for(int i=0; i<len; i++) {
            mp[cuisines[i]].push_back(foods[i]);
            ump[foods[i]]=ratings[i];
            max_rating[cuisines[i]] = max(max_rating[cuisines[i]], ratings[i]);
            fc[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        ump[food]=newRating;
        max_rating[fc[food]] = max(max_rating[fc[food]], newRating);
    }
    
    string highestRated(string cuisine) {
        string ans="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        for(string& food: mp[cuisine]) {
            if(ump[food]==max_rating[cuisine]) {
                ans=min(ans,food);
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}