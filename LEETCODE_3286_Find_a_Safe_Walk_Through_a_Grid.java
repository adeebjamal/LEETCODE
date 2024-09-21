import java.util.*;

class Solution {
    private boolean f(int row, int col, int health, List<List<Integer>> grid, boolean[][] visited, int[][][] dp) {
        if(row == grid.size() - 1 && col == grid.get(0).size() - 1 && health > 0) {
            return grid.get(row).get(col) == 1 && health == 1 ? false : true;
        }
        if(health <= 0 || row < 0 || col < 0 || row >= grid.size() || col >= grid.get(0).size()) {
            return false;
        }
        if(visited[row][col] == true) {
            return false;
        }
        if(dp[row][col][health] != -1) {
            return dp[row][col][health] == 1;
        }
        visited[row][col] = true;
        boolean up = this.f(row - 1, col, health - grid.get(row).get(col), grid, visited, dp);
        boolean down = this.f(row + 1, col, health - grid.get(row).get(col), grid, visited, dp);
        boolean left = this.f(row, col - 1, health - grid.get(row).get(col), grid, visited, dp);
        boolean right = this.f(row, col + 1, health - grid.get(row).get(col), grid, visited, dp);
        visited[row][col] = false;
        boolean result = up || down || left || right;
        dp[row][col][health] = (result == true ? 1 : 0);
        return result;
    }
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        boolean[][] visited = new boolean[grid.size()][grid.get(0).size()];
        for(boolean[] arr: visited) {
            Arrays.fill(arr, false);
        }
        int[][][] dp = new int[grid.size()][grid.get(0).size()][health + 1];
        for(int[][] arr1: dp) {
            for(int[] arr2: arr1) {
                Arrays.fill(arr2, -1);
            }
        }
        return this.f(0, 0, health, grid, visited, dp);
    }
}