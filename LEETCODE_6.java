import java.util.*;

class Solution {
    public String convert(String s, int numRows) {
        if(numRows <= 1) {
            return s;
        }
        String[] arr = new String[numRows];
        Arrays.fill(arr, "");

        int row = 0, direction = -1;
        for(int i = 0; i < s.length(); i++) {
            if(row == 0 || row == numRows - 1) {
                direction *= -1;
            }
            arr[row] += s.charAt(i);
            row += direction == 1 ? 1 : -1;
        }

        String answer = new String("");
        for(String str : arr) {
            answer += str;
        }
        return answer;
    }
}