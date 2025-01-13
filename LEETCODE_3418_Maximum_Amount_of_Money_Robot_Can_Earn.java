// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/

class Solution {
    private int f(int row, int col, int neutralize, int[][] coins, Integer[][][] dp) {
        if(row < 0 || col < 0 || row >= coins.length || col >= coins[0].length) {
            return -10000000;
        }
        if(row == coins.length - 1 && col == coins[0].length - 1) {
            if(coins[row][col] > 0) {
                return coins[row][col];
            }
            return neutralize > 0 ? 0 : coins[row][col];
        }
        if(dp[row][col][neutralize] != null) {
            return dp[row][col][neutralize];
        }
        int add = coins[row][col] + Math.max(this.f(row + 1, col, neutralize, coins, dp), this.f(row, col + 1, neutralize, coins, dp));
        int dodge = -10000000;
        if(coins[row][col] < 0 && neutralize > 0) {
            dodge = Math.max(this.f(row + 1, col, neutralize - 1, coins, dp), this.f(row, col + 1, neutralize - 1, coins, dp));
        }
        dp[row][col][neutralize] = Math.max(add, dodge);
        return dp[row][col][neutralize];
    }
    public int maximumAmount(int[][] coins) {
        Integer[][][] dp = new Integer[coins.length][coins[0].length][3];
        return this.f(0, 0, 2, coins, dp);
    }
}