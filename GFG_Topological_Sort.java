import java.util.*;

class GFG_Topological_Sort {

    public static void dfs(int source, Stack<Integer> st, int[] visited, ArrayList<ArrayList<Integer>> adj) {
        visited[source] = 1;
        for(int neighbour: adj.get(source)) {
            if(visited[neighbour] == 0) {
                dfs(neighbour, st, visited, adj);
            }
        }
        st.push(source);
    }

    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) {
        int[] visited = new int[V];
        Arrays.fill(visited, 0);
        Stack<Integer> st = new Stack<>();
        for(int node = 0; node < V; node++) {
            if(visited[node] == 0) {
                dfs(node, st, visited, adj);
            }
        }
        for(int i = 0; i < V; i++) {
            visited[i] = st.peek();
            st.pop();
        }
        return visited;
    }
}