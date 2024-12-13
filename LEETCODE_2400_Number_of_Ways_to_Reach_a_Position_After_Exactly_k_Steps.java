import java.util.*;

class Solution {

    int mod = (int)(1e9 + 7);

    private int f(int position, int stepsLeft, int target, Map<String, Integer> dp) {
        if(position == target && stepsLeft == 0) {
            return 1;
        }
        if(stepsLeft == 0) {
            return 0;
        }
        String key = position + "_" + stepsLeft;
        if(dp.containsKey(key)) {
            return dp.get(key);
        }
        int left = this.f(position - 1, stepsLeft - 1, target, dp);
        int right = this.f(position + 1, stepsLeft - 1, target, dp);
        dp.put(key, (left % this.mod + right % this.mod) % this.mod);
        return dp.get(key);
    }

    public int numberOfWays(int startPos, int endPos, int k) {
        Map<String, Integer> dp = new HashMap<>();
        return this.f(startPos, k, endPos, dp);
    }
}