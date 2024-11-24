import java.util.*;

class Solution {

    private List<int[]> mstEdges = new ArrayList<>();

    public int minCostConnectPoints(int[][] points) {
        int totalWeightMST = 0;
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for(int i = 0; i < points.length; i++) {
            graph.put(i, new ArrayList<>());
        }
        for(int i = 0; i < points.length - 1; i++) {
            for(int j = 0; j < points.length; j++) {
                int distance = Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1] - points[j][1]);
                graph.get(i).add(new int[] {j, distance});
                graph.get(j).add(new int[] {i, distance});
            }
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        boolean[] visited = new boolean[points.length];
        Arrays.fill(visited, false);
        pq.add(new int[] {0, 0, -1});   // {weight, node, parent};
        while(pq.isEmpty() == false) {
            int weight = pq.peek()[0], node = pq.peek()[1], parent = pq.peek()[2];
            pq.poll();
            if(visited[node] == true) {
                continue;
            }
            if(parent != -1) {
                this.mstEdges.add(new int[] {parent, node});
            }
            totalWeightMST += weight;
            visited[node] = true;
            for(int[] edge: graph.get(node)) {
                int neighbour = edge[0], distance = edge[1];
                if(visited[neighbour] == false) {
                    pq.add(new int[] {distance, neighbour, node});
                }
            }
        }
        return totalWeightMST;
    }
}