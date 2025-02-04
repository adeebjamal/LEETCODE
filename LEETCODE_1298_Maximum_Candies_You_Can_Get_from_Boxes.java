// https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/
import java.util.*;

class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        int n = status.length;
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);

        Set<Integer> keyHash = new HashSet<>();
        Set<Integer> boxes = new HashSet<>();
        Queue<Integer> q = new LinkedList<>();

        for(int i = 0; i < initialBoxes.length; i++) {
            if(status[initialBoxes[i]] == 1) {
                q.add(initialBoxes[i]);
            }
            boxes.add(initialBoxes[i]);
        }

        int candyCount = 0;
        while(!q.isEmpty()) {

            int currentBox = q.poll();
            candyCount += candies[currentBox];

            for(int nextBox: keys[currentBox]) {
                keyHash.add(nextBox);
                if(boxes.contains(nextBox) && status[nextBox] == 0 && !visited[nextBox]) {
                    status[nextBox] = 1;
                    q.add(nextBox);
                    visited[nextBox] = true;
                }
            }

            for(int containedBox: containedBoxes[currentBox]) {
                boxes.add(containedBox);
                if((status[containedBox] == 1 || keyHash.contains(containedBox)) && !visited[containedBox]) {
                    status[containedBox] = 1;
                    q.add(containedBox);
                    visited[containedBox] = true;
                }
            }

        }

        return candyCount;
    }
}