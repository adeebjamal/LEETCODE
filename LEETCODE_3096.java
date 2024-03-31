import java.util.*;

class Solution {
    public int minimumLevels(int[] possible) {
        List<Integer> prefixSum = new ArrayList<>();
        int sum = 0;
        for(int bit : possible) {
            sum += (bit == 1 ? 1 : -1);
            prefixSum.add(sum);
        }
        for(int i = 0; i < prefixSum.size(); i++) {
            int leftSum = prefixSum.get(i), rightSum = prefixSum.get(prefixSum.size() - 1) - prefixSum.get(i);
            if(leftSum > rightSum) {
                return i + 1 == possible.length ? -1 : i + 1;
            }
        }
        return -1;
    }
}