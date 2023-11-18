import java.util.*;

class LEETCODE_1615_Maximal_Network_Rank {
    public int maximalNetworkRank(int n, int[][] roads) {
        Map<Integer,Integer> neighbours = new HashMap<>();
        int[][] connected = new int[n][n];
        for(int[] road: roads) {
            if(!neighbours.containsKey(road[0])) {
                neighbours.put(road[0], 0);
            }
            if(!neighbours.containsKey(road[1])) {
                neighbours.put(road[1], 0);
            }
            neighbours.put(road[0], neighbours.get(road[0])+1);
            neighbours.put(road[1], neighbours.get(road[1])+1);
            connected[road[1]][road[0]] = 1;
            connected[road[0]][road[1]] = 1;
        }
        int score = Integer.MIN_VALUE;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int score1 = 0, score2 = 0;
                if(neighbours.containsKey(i)) {
                    score1 = neighbours.get(i);
                }
                if(neighbours.containsKey(j)) {
                    score2 = neighbours.get(j);
                }
                score = Math.max(score, score1 + score2 - connected[i][j]);
            }
        }
        return score;
    }
}