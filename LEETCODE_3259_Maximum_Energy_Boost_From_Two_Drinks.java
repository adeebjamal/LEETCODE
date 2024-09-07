import java.util.*;

class Solution {
    private long f(int index, int currentBatch, int[] energyDrinkA, int[] energyDrinkB, long[][] dp) {
        if(index >= energyDrinkA.length) {
            return 0;
        }
        if(dp[index][currentBatch] != -1) {
            return dp[index][currentBatch];
        }
        long left = 0, right = 0;
        if(currentBatch == 0) {
            left = energyDrinkA[index] + this.f(index + 1, 0, energyDrinkA, energyDrinkB, dp);
            right = energyDrinkA[index] + this.f(index + 2, 1, energyDrinkA, energyDrinkB, dp);
        }
        else if(currentBatch == 1) {
            left = energyDrinkB[index] + this.f(index + 1, 1, energyDrinkA, energyDrinkB, dp);
            right = energyDrinkB[index] + this.f(index + 2, 0, energyDrinkA, energyDrinkB, dp);
        }
        return dp[index][currentBatch] = Math.max(left, right);
    }
    public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
        long[][] dp1 = new long[energyDrinkA.length][2];
        long[][] dp2 = new long[energyDrinkB.length][2];
        for(int i = 0; i < energyDrinkA.length; i++) {
            Arrays.fill(dp1[i], -1L);
            Arrays.fill(dp2[i], -1L);
        }
        return Math.max(this.f(0, 0, energyDrinkA, energyDrinkB, dp1), this.f(0, 1, energyDrinkA, energyDrinkB, dp2));
    }
}