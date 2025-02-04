// https://leetcode.com/problems/remove-methods-from-project/description/
import java.util.*;

class Solution {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int method = 0; method < n; method++) {
            graph.put(method, new ArrayList<>());
        }
        for(int[] edge: invocations) {
            graph.get(edge[0]).add(edge[1]);
        }
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        Queue<Integer> q = new LinkedList<>();
        q.add(k);
        visited[k] = true;
        while(!q.isEmpty()) {
            int node = q.poll();
            for(int neighbour: graph.get(node)) {
                if(!visited[neighbour]) {
                    q.add(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        boolean flag = false;
        for(int method = 0; method < n; method++) {
            if(!visited[method]) {
                for(int neighbour: graph.get(method)) {
                    if(visited[neighbour]) {
                        flag = true;
                    }
                }
            }
        }
        List<Integer> answer = new ArrayList<>();
        for(int method = 0; method < n; method++) {
            if((visited[method] && flag) || !visited[method]) {
                answer.add(method);
            }
        }
        return answer;
    }
}