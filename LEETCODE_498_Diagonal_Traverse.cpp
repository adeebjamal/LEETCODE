#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> answer;
    vector<int> traverse1(int& row, vector<vector<int>>& mat) {
        vector<int> result;
        for(int i = row, j = 0; i >= 0 and j < mat[0].size(); i--, j++) {
            result.push_back(mat[i][j]);
        }
        return result;
    }
    vector<int> traverse2(int& col, vector<vector<int>>& mat) {
        vector<int> result;
        for(int i = mat.size()-1, j = col; i >= 0 and j < mat[0].size() ; i--, j++) {
            result.push_back(mat[i][j]);
        }
        return result;
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool Reverse = false;
        for(int i = 0; i < mat.size(); i++) {
            vector<int> result = this->traverse1(i, mat);
            if(Reverse == true) {
                reverse(result.begin(), result.end());
            }
            for(int& num: result) {
                this->answer.push_back(num);
            }
            Reverse = !Reverse;
        }
        for(int j = 1; j < mat[0].size(); j++) {
            vector<int> result = this->traverse2(j, mat);
            if(Reverse == true) {
                reverse(result.begin(), result.end());
            }
            for(int& num: result) {
                this->answer.push_back(num);
            } 
            Reverse = !Reverse;
        }
        return this->answer;
    }
};