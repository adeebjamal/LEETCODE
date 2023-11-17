import java.util.*;

class LEETCODE_2993 {

    public int findChampion(int[][] grid) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for(int i = 0; i < grid.length; i++) {
            mp.put(i, new ArrayList<>());
        }
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[i].length; j++) {
                if(i == j) {
                    continue;
                }
                else if(grid[i][j] == 1) {
                    mp.get(j).add(i);
                }
                else if(grid[i][j] == 0) {
                    mp.get(i).add(j);
                }
            }
        }
        for(int i = 0; i < grid.length; i++) {
            if(mp.get(i).size() == 0) {
                return i;
            }
        }
        return -1;
    }
}