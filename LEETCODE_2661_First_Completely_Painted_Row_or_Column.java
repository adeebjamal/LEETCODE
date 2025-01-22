// https://leetcode.com/problems/first-completely-painted-row-or-column/description/

import java.util.*;

class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int rowCount = mat.length, colCount = mat[0].length;
        int[] rowHash = new int[rowCount];
        int[] colHash = new int[colCount];
        Arrays.fill(rowHash, 0);
        Arrays.fill(colHash, 0);
        Map<Integer, int[]> hash = new HashMap<>();
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < colCount; j++) {
                hash.put(mat[i][j], new int[] {i, j});
            }
        }
        for(int i = 0; i < arr.length; i++) {
            int num = arr[i];
            int row = hash.get(num)[0], col = hash.get(num)[1];
            rowHash[row]++;
            colHash[col]++;
            if(rowHash[row] == colCount || colHash[col] == rowCount) {
                return i;
            }
        }
        return -1;
    }
}