import java.util.*;

class LEETCODE_1743_Restore_the_Array_From_Adjacent_Pairs {
    public void dfs(int source, Map<Integer,List<Integer>> graph, Set<Integer> visited, List<Integer> answer) {
        visited.add(source);
        answer.add(source);
        for(int neighbour: graph.get(source)) {
            if(!visited.contains(neighbour)) {
                this.dfs(neighbour, graph, visited, answer);
            }
        }
    }
    public int[] restoreArray(int[][] adjacentPairs) {
        Map<Integer,List<Integer>> graph = new HashMap<>();
        for(int[] pair : adjacentPairs) {
            if(!graph.containsKey(pair[0])) {
                graph.put(pair[0], new ArrayList<>());
            }
            graph.get(pair[0]).add(pair[1]);
            if(!graph.containsKey(pair[1])) {
                graph.put(pair[1], new ArrayList<>());
            }
            graph.get(pair[1]).add(pair[0]);
        }
        int source = 0;
        for(int key: graph.keySet()) {
            if(graph.get(key).size() == 1) {
                source = key;
                break;
            }
        }
        Set<Integer> visited = new HashSet<>();
        List<Integer> answer = new ArrayList<>();
        this.dfs(source, graph, visited, answer);
        int[] result = new int[answer.size()];
        for(int i = 0; i < answer.size(); i++) {
            result[i] = answer.get(i);
        }
        return result;
    }
}