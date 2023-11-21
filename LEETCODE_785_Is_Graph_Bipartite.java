import java.util.*;

class LEETCODE_785_Is_Graph_Bipartite {

    private boolean bfs(int source, int[] color, int[][] graph) {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.offerLast(source);
        color[source] = 0;
        while(!q.isEmpty()) {
            int node = q.pollFirst();
            for(int neighbour: graph[node]) {
                if(color[neighbour] == -1) {
                    q.offerLast(neighbour);
                    color[neighbour] = (color[node] + 1) % 2;
                }
                else if(color[neighbour] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean dfs(int source, int start_color, int[] color, int[][] graph) {
        color[source] = start_color;
        for(int neighbour: graph[source]) {
            if(color[neighbour] == -1) {
                if(this.dfs(neighbour, (start_color + 1) % 2, color, graph) == false) {
                    return false;
                }
            }
            else if(color[source] == color[neighbour]) {
                return false;
            }
        }
        return true;
    }

    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        Arrays.fill(color, -1);
        for(int node = 0; node < n; node++) {
            if(color[node] == -1) {
                // if(this.bfs(node, color, graph) == false) {
                //     return false;
                // }
                if(this.dfs(node, 0, color, graph) == false) {
                    return false;
                }
            }
        }
        return true;
    }
}