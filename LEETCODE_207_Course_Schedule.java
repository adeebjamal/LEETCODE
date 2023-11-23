import java.util.*;

public class LEETCODE_207_Course_Schedule {

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        int[] indegree = new int[numCourses];
        Arrays.fill(indegree, 0);
        for(int[] p: prerequisites) {
            int course = p[0], prerequisite = p[1];
            if(graph.containsKey(prerequisite) == false) {
                graph.put(prerequisite, new ArrayList<>());
            }
            graph.get(prerequisite).add(course);
            indegree[course]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for(int node = 0; node < numCourses; node++) {
            if(indegree[node] == 0) {
                q.offer(node);
            }
        }
        List<Integer> toposort = new ArrayList<>();
        while(q.isEmpty() == false) {
            int node = q.poll();
            toposort.add(node);
            if(graph.containsKey(node) == true) {
                for(int neighbour: graph.get(node)) {
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0) {
                        q.offer(neighbour);
                    }
                }
            }
        }
        return toposort.size() == numCourses;
    }
}