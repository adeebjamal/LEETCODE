import java.util.*;

class LEETCODE_1042_Flower_Planting_With_No_Adjacent {
    public int[] gardenNoAdj(int n, int[][] paths) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int[] path: paths) {
            if(!graph.containsKey(path[0]-1)) {
                graph.put(path[0]-1, new ArrayList<>());
            }
            if(!graph.containsKey(path[1]-1)) {
                graph.put(path[1]-1, new ArrayList<>());
            }
            graph.get(path[0]-1).add(path[1]-1);
            graph.get(path[1]-1).add(path[0]-1);
        }
        int[] flower = new int[n];
        Arrays.fill(flower,-1);
        for(int garden = 0; garden < n; garden++) {
            Set<Integer> used_flowers = new HashSet<>();
            if(graph.containsKey(garden)) {
                for(int neighbour: graph.get(garden)) {
                    used_flowers.add(flower[neighbour]);
                }
            }
            for(int flower_option = 1; flower_option <= 4; flower_option++) {
                if(!used_flowers.contains(flower_option)) {
                    flower[garden] = flower_option;
                    break;
                }
            }
        }
        return flower;
    }
}