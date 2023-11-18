import java.util.*;

class LEETCODE_2285_Maximum_Total_Importance_of_Roads {
    public long maximumImportance(int n, int[][] roads) {
        int[] degree = new int[n];
        Arrays.fill(degree, 0);
        for(int[] road: roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(b[0], a[0]));
        for(int i = 0; i < n; i++) {
            pq.offer(new int[]{degree[i], i});
        }
        int count = n;
        int[] ranks = new int[n];
        while(!pq.isEmpty()) {
            int[] top = pq.poll();
            ranks[top[1]] = count--;
        }
        long answer = 0;
        for(int[] road: roads) {
            answer += ranks[road[0]] + ranks[road[1]];
        }
        return answer;
    }
}