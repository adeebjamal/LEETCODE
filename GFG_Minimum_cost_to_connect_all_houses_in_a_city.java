import java.util.*;

class Solution {

    public int minCostCity(int[][] houses, int n) {
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for(int i = 0; i < n; i++) {
            graph.put(i, new ArrayList<>());
        }
        for(int i = 0; i < houses.length - 1; i++) {
            for(int j = i + 1; j < houses.length; j++) {
                int distance = Math.abs(houses[i][0] - houses[j][0]);
                distance += Math.abs(houses[i][1] - houses[j][1]);
                graph.get(i).add(new int[] {j, distance});
                graph.get(j).add(new int[] {i, distance});
            }
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        // {weight, node}
        boolean[] visited = new boolean[n];
        pq.add(new int[] {0, 0});
        int mstWeight = 0;
        while(pq.isEmpty() == false) {
            int weight = pq.peek()[0], node = pq.peek()[1];
            pq.poll();
            if(visited[node] == true) {
                continue;
            }
            mstWeight += weight;
            visited[node] = true;
            for(int[] edge: graph.get(node)) {
                int neighbour = edge[0], edgeWeight = edge[1];
                if(visited[neighbour] == false) {
                    pq.add(new int[] {edgeWeight, neighbour});
                }
            }
        }
        return mstWeight;
    }
}