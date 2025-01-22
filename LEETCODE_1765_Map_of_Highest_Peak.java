// https://leetcode.com/problems/map-of-highest-peak/description/

import java.util.*;

class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int rows = isWater.length, cols = isWater[0].length;
        int[][] height = new int[rows][cols];
        for(int i = 0; i < height.length; i++) {
            Arrays.fill(height[i], -1);
        }
        Queue<int[]> q = new LinkedList<>();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.add(new int[] {i, j, 0});
                }
            }
        }
        int[] dr = new int[] {-1, 0, 1, 0};
        int[] dc = new int[] {0, -1, 0, 1};
        while(!q.isEmpty()) {
            int row = q.peek()[0], col = q.peek()[1], distance = q.peek()[2];
            q.poll();
            for(int i = 0; i < 4; i++) {
                int newRow = row + dr[i], newCol = col + dc[i];
                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    if(isWater[newRow][newCol] == 0 && height[newRow][newCol] == -1) {
                        height[newRow][newCol] = distance + 1;
                        q.add(new int[] {newRow, newCol, distance + 1});
                    }
                }
            }
        }
        return height;
    }
}