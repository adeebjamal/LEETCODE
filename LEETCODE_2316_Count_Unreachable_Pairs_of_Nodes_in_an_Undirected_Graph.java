import java.util.*;

class LEETCODE_2316_Count_Unreachable_Pairs_of_Nodes_in_an_Undirected_Graph {

    private int bfs(int source, boolean[] visited, Map<Integer, List<Integer>> graph) {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.offerLast(source);
        visited[source] = true;
        int count = 0;
        while(!q.isEmpty()) {
            int node = q.pollFirst();
            count++;
            List<Integer> neighbours = new ArrayList<>();
            if(graph.containsKey(node)) {
                neighbours = graph.get(node);
            }
            for(int neighbour: neighbours) {   // "java.util.Map.get(Object)" is null
                if(!visited[neighbour]) {
                    q.offerLast(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return count;
    }

    public long countPairs(int n, int[][] edges) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int[] edge: edges) {
            if(!graph.containsKey(edge[0])) {
                graph.put(edge[0], new ArrayList<>());
            }
            if(!graph.containsKey(edge[1])) {
                graph.put(edge[1], new ArrayList<>());
            }
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        long answer = 0, component_sizes = 0;
        for(int node = 0; node < n; node++) {
            if(!visited[node]) {
                long size = this.bfs(node, visited, graph);
                answer += component_sizes * size;
                component_sizes += size;
            }
        }
        return answer;
    }
}