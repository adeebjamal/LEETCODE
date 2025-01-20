// https://leetcode.com/problems/paint-house-iv/description/

class Solution {

    int n = 0;

    private long f(int index, int leftColor, int rightColor, int[][] cost, Long[][][] dp) {
        if(index >= n / 2) {
            return 0;
        }
        if(dp[index][leftColor][rightColor] != null) {
            return dp[index][leftColor][rightColor];
        }
        long answer = 1000000000000000L;
        for(int i = 0; i < 3; i++) {
            if(i != leftColor) {
                for(int j = 0 ; j < 3; j++) {
                    if(j != rightColor && i != j) {
                        long currentCost = cost[index][i] + cost[this.n - index - 1][j] + this.f(index + 1, i, j, cost, dp);
                        answer = Math.min(answer, currentCost);
                    }
                }
            }
        }
        dp[index][leftColor][rightColor] = answer;
        return answer;
    }

    public long minCost(int n, int[][] cost) {
        this.n = cost.length;
        long answer = 1000000000000000L;
        Long[][][] dp = new Long[n][4][4];
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i != j) {
                    long currentCost = this.f(0, i, j, cost, dp);
                    answer = Math.min(answer, currentCost);
                }
            }
        }
        return answer;
    }
}