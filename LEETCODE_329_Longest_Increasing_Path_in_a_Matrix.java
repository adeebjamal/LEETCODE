// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
import java.util.*;

class Solution {

    private int rows = 0, cols = 0;

    private boolean check(int row, int col) {
        return row >= 0 && row < this.rows && col >= 0 && col < this.cols;
    }

    private int f(int row, int col, int[][] grid, int[][] dp) {
        if(!this.check(row, col)) {
            return 0;
        }
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        int up = 0, down = 0, left = 0, right = 0;
        if(this.check(row - 1, col) && grid[row - 1][col] > grid[row][col]) {
            up = this.f(row - 1, col, grid, dp);
        }
        if(this.check(row + 1, col) && grid[row + 1][col] > grid[row][col]) {
            down = this.f(row + 1, col, grid, dp);
        }
        if(this.check(row, col - 1) && grid[row][col - 1] > grid[row][col]) {
            left = this.f(row, col - 1, grid, dp);
        }
        if(this.check(row, col + 1) && grid[row][col + 1] > grid[row][col]) {
            right = this.f(row, col + 1, grid, dp);
        }
        dp[row][col] = 1 + Math.max(up, Math.max(down, Math.max(left, right)));
        return dp[row][col];
    }

    public int longestIncreasingPath(int[][] matrix) {
        this.rows = matrix.length;
        this.cols = matrix[0].length;
        int[][] dp = new int[this.rows][this.cols];
        for(int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        int answer = 1;
        for(int i = 0; i < this.rows; i++) {
            for(int j = 0; j < this.cols; j++) {
                answer = Math.max(answer, this.f(i, j, matrix, dp));
            }
        }
        return answer;
    }
}