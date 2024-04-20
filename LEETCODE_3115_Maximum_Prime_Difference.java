import java.util.*;

class Solution {
    private boolean check(int number) {
        if(number == 1) {
            return false;
        }
        double root = Math.sqrt(number);
        for(int num = 2; num <= root; num++) {
            if(number % num == 0) {
                return false;
            }
        }
        return true;
    }
    public int maximumPrimeDifference(int[] nums) {
        int index1 = 0, index2 = 0, len = nums.length;
        for(int idx = 0; idx < len; idx++) {
            if(this.check(nums[idx])) {
                index1 = idx;
                break;
            }
        }
        for(int idx = len - 1; idx >= 0; idx--) {
            if(this.check(nums[idx])) {
                index2 = idx;
                break;
            }
        }
        return Math.abs(index1 - index2);
    }
}