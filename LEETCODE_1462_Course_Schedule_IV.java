import java.util.*;

class LEETCODE_1462_Course_Schedule_IV {

    private boolean bfs(int source, int destination, Set<Integer> visited, Map<Integer, List<Integer>> graph) {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.offerLast(source);
        visited.add(source);
        while(!q.isEmpty()) {
            int node = q.pollFirst();
            if(node == destination) {
                return true;
            }
            if(graph.containsKey(node)) {
                for(int neighbour: graph.get(node)) {
                    if(!visited.contains(neighbour)) {
                        q.offerLast(neighbour);
                        visited.add(neighbour);
                    }
                }
            }
        }
        return false;
    }

    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int[] vec: prerequisites) {
            if(!graph.containsKey(vec[0])) {
                graph.put(vec[0], new ArrayList<>());
            }
            graph.get(vec[0]).add(vec[1]);
        }
        List<Boolean> answer = new ArrayList<>();
        for(int[] query: queries) {
            Set<Integer> visited = new HashSet<>();
            answer.add(this.bfs(query[0], query[1], visited, graph));
        }
        return answer;
    }
}