import java.util.*;

public class LEETCODE_498_Diagonal_Traverse {

    private void reverse(List<Integer> arr) {
        int start = 0, end = arr.size()-1;
        while(start <= end) {
            int temp = arr.get(start);
            arr.set(start++, arr.get(end));
            arr.set(end--, temp);
        }
    }

    private List<Integer> traverse1(int row, int[][] mat) {
        List<Integer> result = new ArrayList<>();
        for(int i = row, j = 0; i >= 0 && j < mat[0].length; i--, j++) {
            result.add(mat[i][j]);
        }
        return result;
    }

    private List<Integer> traverse2(int col, int[][] mat) {
        List<Integer> result = new ArrayList<>();
        for(int i = mat.length-1, j = col; i >= 0 && j < mat[0].length; i--, j++) {
            result.add(mat[i][j]);
        }
        return result;
    }

    public int[] findDiagonalOrder(int[][] mat) {
        boolean reverse = false;
        int[] answer = new int[mat.length * mat[0].length];
        int index = 0;
        for(int i = 0; i < mat.length; i++) {
            List<Integer> result = this.traverse1(i, mat);
            if(reverse == true) {
                this.reverse(result);
            }
            for(int num: result) {
                answer[index++] = num;
            }
            reverse = !reverse;
        }
        for(int j = 1; j < mat[0].length; j++) {
            List<Integer> result = this.traverse2(j, mat);
            if(reverse == true) {
                this.reverse(result);
            }
            for(int num: result) {
                answer[index++] = num;
            }
            reverse = !reverse;
        }
        return answer;
    }
}