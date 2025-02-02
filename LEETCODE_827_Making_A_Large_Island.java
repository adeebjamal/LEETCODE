// https://leetcode.com/problems/making-a-large-island/description/
import java.util.*;

class Solution {

    int[] dr = new int[] {-1, 0, 1, 0};
    int[] dc = new int[] {0, -1, 0, 1};

    private int bfs(int row, int col, int componentId, int[][] grid, boolean[][] visited, Map<String, int[]> hash) {
        Queue<int[]> q = new LinkedList<>();
        List<int[]> cells = new ArrayList<>();
        q.add(new int[] {row, col});
        cells.add(new int[] {row, col});
        visited[row][col] = true;
        int size = 0;
        while(!q.isEmpty()) {
            int currRow = q.peek()[0], currCol = q.peek()[1];
            q.poll();
            size++;
            for(int i = 0; i < 4; i++) {
                int newRow = currRow + this.dr[i], newCol = currCol + this.dc[i];
                if(newRow >= 0 && newRow < grid.length && newCol >= 0 && newCol < grid[0].length) {
                    if(grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                        q.add(new int[] {newRow, newCol});
                        cells.add(new int[] {newRow, newCol});
                        visited[newRow][newCol] = true;
                    }
                }
            }
        }
        for(int[] cell: cells) {
            hash.put(Arrays.toString(cell), new int[] {size, componentId});
        }
        return size;
    }

    public int largestIsland(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        List<int[]> zeroCells = new ArrayList<>();
        for(int i = 0; i < rows; i++) {
            Arrays.fill(visited[i], false);
        }
        int componentId = 0;
        Map<String, int[]> hash = new HashMap<>();   // cell -> {size, componentId}
        int answer = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    answer = Math.max(answer, this.bfs(i, j, componentId, grid, visited, hash));
                    componentId++;
                }
                else if(grid[i][j] == 0) {
                    zeroCells.add(new int[] {i, j});
                }
            }
        }
        if(zeroCells.size() == rows * cols) {
            return 1;
        }
        if(hash.size() == rows * cols) {
            return answer;
        }
        for(int[] cell: zeroCells) {
            int row = cell[0], col = cell[1], currArea = 0;
            Set<Integer> compIdHash = new HashSet<>();
            for(int i = 0; i < 4; i++) {
                int newRow = row + this.dr[i], newCol = col + this.dc[i];
                if(newRow >= 0 && newRow < grid.length && newCol >= 0 && newCol < grid[0].length) {
                    String newCell = Arrays.toString(new int[] {newRow, newCol});
                    if(hash.containsKey(newCell)) {
                        int area = hash.get(newCell)[0], compId = hash.get(newCell)[1];
                        if(!compIdHash.contains(compId)) {
                            currArea += area;
                            compIdHash.add(compId);
                        }
                    }
                }
            }
            answer = Math.max(answer, 1 + currArea);
        }
        return answer;
    }
}