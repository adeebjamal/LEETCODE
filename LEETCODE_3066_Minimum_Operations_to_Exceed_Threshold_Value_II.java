import java.util.*;

class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for(int num: nums) {
            pq.add(num * 1L);
        }
        int opsCount = 0;
        while(pq.size() > 1 && pq.peek() < k) {
            long min = pq.poll();
            long max = pq.poll();
            pq.add(2L * min + max);
            opsCount++;
        }
        return opsCount;
    }
}