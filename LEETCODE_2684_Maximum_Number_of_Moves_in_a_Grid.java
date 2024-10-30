import java.util.*;

class Solution {
    int rows = 0;
    int cols = 0;
    boolean check(int row, int col) {
        return row >= 0 && col >= 0 && row < this.rows && col < this.cols;
    }
    int f(int row, int col, int[][] grid, int[][] dp) {
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        int one = 0, two = 0, three = 0;
        if(this.check(row - 1, col + 1)) {
            one = (grid[row - 1][col + 1] > grid[row][col]) ? 1 + this.f(row - 1, col + 1, grid, dp) : 0;
        }
        if(this.check(row, col + 1)) {
            two = (grid[row][col + 1] > grid[row][col]) ? 1 + this.f(row, col + 1, grid, dp) : 0;
        }
        if(this.check(row + 1, col + 1)) {
            three = (grid[row + 1][col + 1] > grid[row][col]) ? 1 + this.f(row + 1, col + 1, grid, dp) : 0;
        }
        return dp[row][col] = Math.max(one, Math.max(two, three));
    }
    public int maxMoves(int[][] grid) {
        this.rows = grid.length;
        this.cols = grid[0].length;
        int answer = 0;
        int[][] dp = new int[this.rows][this.cols];
        for(int i = 0; i < this.rows; i++) {
            for(int j = 0; j < this.cols; j++) {
                dp[i][j] = -1;
            }
        }
        for(int row = 0; row < this.rows; row++) {
            answer = Math.max(answer, this.f(row, 0, grid, dp));
        }
        return answer;
    }
}