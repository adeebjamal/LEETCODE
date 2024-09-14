import java.util.*;

class Solution {
    private int f(int index, String str, int[] dp) {
        if(index >= str.length()) {
            return 1;
        }
        if(str.charAt(index) == '0') {
            return 0;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        int left = 0, right = 0;
        left = this.f(index + 1, str, dp);
        if(index + 1 < str.length()) {
            if((str.charAt(index) == '1') || (str.charAt(index) == '2' && str.charAt(index + 1) <= '6')) {
                right = this.f(index + 2, str, dp);
            }
        }
        return dp[index] = left + right;
    }
    public int numDecodings(String s) {
        int[] dp = new int[s.length()];
        Arrays.fill(dp, -1);
        return this.f(0, s, dp);
    }
}