import java.util.*;

class Solution {
    private int f(int index, int target, int[] nums, Map<String, Integer> dp) {
        if(index == nums.length && target == 0) {
            return 1;
        }
        if(index >= nums.length) {
            return 0;
        }
        String key = String.valueOf(index) + "_" + String.valueOf(target);
        if(dp.containsKey(key)) {
            return dp.get(key);
        }
        int num1 = nums[index], num2 = -1 * nums[index];
        int left = this.f(index + 1, target - num1, nums, dp);
        int right = this.f(index + 1, target - num2, nums, dp);
        dp.put(key, left + right);
        return left + right;
    }
    public int findTargetSumWays(int[] nums, int target) {
        Map<String, Integer> dp = new HashMap<>();
        return this.f(0, target, nums, dp);
    }
}