// https://leetcode.com/problems/flood-fill/
#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int initialColor=0;
//     int rows=0;
//     int cols=0;
//     void dfs(int row, int col, vector<vector<int>>& image, int color) {
//         if(row<0 or row>=this->rows or col<0 or col>=this->cols) {
//             return;
//         }
//         if(image[row][col] != this->initialColor) {
//             return;
//         }
//         image[row][col] = color;
//         dfs(row-1,col,image,color);
//         dfs(row+1,col,image,color);
//         dfs(row,col-1,image,color);
//         dfs(row,col+1,image,color);
//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         this->initialColor = image[sr][sc];
//         this->rows = image.size();
//         this->cols = image[0].size();
//         this->dfs(sr,sc,image,color);
//         return image;
//     }
// };
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int row,int col,int source){
        if(sr<0 || sr>=row || sc<0 || sc>=col){
            return;
        }
        else if(image[sr][sc]!=source){
            return;
        }
        image[sr][sc]=color;
        dfs(image,sr-1,sc,color,row,col,source);
        dfs(image,sr+1,sc,color,row,col,source);
        dfs(image,sr,sc-1,color,row,col,source);
        dfs(image,sr,sc+1,color,row,col,source);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc]){
            return image;
        }
        int row=image.size();
        int col=image[0].size();
        int source = image[sr][sc];
        dfs(image,sr,sc,color,row,col,source);
        return image ;
    }
};
int main() {
    Solution* obj = new Solution();
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    for(vector<int>& row: obj->floodFill(image,1,1,2)) {
        for(int& pixel: row) {
            cout<<pixel<<" ";
        }
        cout<<endl;
    }
    return 0;
}