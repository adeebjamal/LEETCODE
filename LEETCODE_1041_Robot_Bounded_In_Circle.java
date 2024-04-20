import java.util.*;

class Solution {
    public boolean isRobotBounded(String instructions) {
        int x = 0, y = 0, direction = 0;
        int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
        for(int i = 0; i < instructions.length(); i++) {
            if(instructions.charAt(i) == 'R') {
                direction = (direction + 1) % 4;
            }
            else if(instructions.charAt(i) == 'L') {
                direction = (direction + 3) % 4;
            }
            else {
                x += dx[direction];
                y += dy[direction];
            }
        }
        return (x == 0 && y == 0) || direction != 0;
    }
}