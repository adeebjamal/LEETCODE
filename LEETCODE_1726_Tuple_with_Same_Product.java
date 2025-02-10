import java.util.*;

class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> hash = new HashMap<>();
        int n = nums.length;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                if(!hash.containsKey(product)) {
                    hash.put(product, 0);
                }
                hash.put(product, 1 + hash.get(product));
            }
        }
        int count = 0;
        for(int key: hash.keySet()) {
            int len = hash.get(key);
            count += len * (len - 1) / 2;
        }
        // Multiplying by 8 because each unique tuple can make 7 new tuples
        return count * 8;
    }
}