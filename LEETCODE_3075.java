import java.util.*;

public class LEETCODE_3075 {

    public long maximumHappinessSum(int[] happiness, int k) {
        int[] copy = Arrays.copyOf(happiness, happiness.length);
        Arrays.sort(copy);
        long answer = 0;
        int index = copy.length - 1, counter = 0;

        while(index >= 0) {
            if(copy[index] - counter >= 0) {
                answer += copy[index--] - counter++;
            }
            else {
                break;
            }
            if(counter == k) {
                break;
            }
        }

        return answer;

    }

}