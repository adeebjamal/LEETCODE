import java.util.*;

class Solution {
    public int findChampion(int n, int[][] edges) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i = 0; i < n; i++) {
            mp.put(i,1);
        }
        for(int i = 0; i < edges.length; i++) {
            mp.put(edges[i][1], 0);
        }
        int answer = -1, winnerCount = 0;
        for(int i = 0; i < n; i++) {
            if(mp.get(i) == 1) {
                answer = i;
                winnerCount++;
            }
        }
        return (winnerCount == 1) ? answer : -1;
    }
}