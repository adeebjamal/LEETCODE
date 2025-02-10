import java.util.*;

class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        int n = queries.length;
        Map<Integer, Integer> ballColor = new HashMap<>();
        Map<Integer, Integer> colorCount = new HashMap<>();
        int[] answer = new int[n];

        for(int i = 0; i < n; i++) {
            int ball = queries[i][0], newColor = queries[i][1];
            int oldColor = ballColor.containsKey(ball) ? ballColor.get(ball) : -1;
            ballColor.put(ball, newColor);
            if(oldColor != -1) {
                colorCount.put(oldColor, colorCount.get(oldColor) - 1);
                if(colorCount.get(oldColor) == 0) {
                    colorCount.remove(oldColor);
                }
            }
            if(!colorCount.containsKey(newColor)) {
                colorCount.put(newColor, 0);
            }
            colorCount.put(newColor, 1 + colorCount.get(newColor));
            answer[i] = colorCount.size();
        }
        return answer;
    }
}