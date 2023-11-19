import java.util.*;

class LEETCODE_2374_Node_With_Highest_Edge_Score {
    public int edgeScore(int[] edges) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int node = 0; node < edges.length; node++) {
            if(!graph.containsKey(edges[node])) {
                graph.put(edges[node], new ArrayList<>());
            }
            graph.get(edges[node]).add(node);
        }
        long max_score = 0;
        int answer = -1;
        for(int node = 0; node < edges.length; node++) {
            long score = 0;
            if(graph.containsKey(node)) {
                for(int neighbour: graph.get(node)) {
                    score += neighbour;
                }
            }
            if(score > max_score) {
                max_score = score;
                answer = node;
            }
        }
        return answer;
    }
}