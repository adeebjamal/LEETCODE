import java.util.*;

public class GFG_Alien_Dictionary {

    private Stack<Character> st = new Stack<>();

    void dfs(char source, Set<Character> visited, Map<Character, List<Character>> graph) {
        visited.add(source);
        if(graph.containsKey(source) == true) {
            for(char neighbour: graph.get(source)) {
                if(visited.contains(neighbour) == false) {
                    this.dfs(neighbour, visited, graph);
                }
            }
        }
        this.st.push(source);
    }

    public String findOrder(String [] dict, int N, int K) {
        Map<Character, List<Character>> graph = new HashMap<>();
        for(int i = 0; i < dict.length-1; i++) {
            String s = dict[i], t = dict[i+1];
            int len = Math.min(s.length(), t.length());
            for(int j = 0; j < len; j++) {
                if(s.charAt(j) != t.charAt(j)) {
                    if(graph.containsKey(s.charAt(j)) == false) {
                        graph.put(s.charAt(j) , new ArrayList<>());
                    }
                    graph.get(s.charAt(j)).add(t.charAt(j));
                    break;
                }
            }
        }
        Set<Character> visited = new HashSet<>();
        for(char node = 'a'; node < (char)('a' + K); node++) {
            if(visited.contains(node) == false) {
                this.dfs(node, visited, graph);
            }
        }
        String answer = "";
        while(this.st.isEmpty() == false) {
            answer += this.st.peek();
            this.st.pop();
        }
        return answer;
    }
}