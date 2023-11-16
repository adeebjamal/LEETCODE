import java.util.*;

class LEETCODE_1980 {

    private static int decimal(String num) {
        int value = 0;
        for(char bit: num.toCharArray()) {
            value = value*2 + (bit - '0');
        }
        return value;
    }

    private static String binary(int num) {
        List<Integer> result = new ArrayList<>();
        while(num != 0) {
            result.add(num % 2);
            num/= 2;
        }
        String answer = "";
        for(int i = result.size()-1; i >= 0; i--) {
            answer+= (char)(result.get(i) + '0');
        }
        return answer;
    }

    public String findDifferentBinaryString(String[] nums) {
        Set<Integer> hash = new HashSet<>();
        for(String num: nums) {
            int value = decimal(num);
            hash.add(value);
        }
        int maxi = (int)Math.pow(2, nums[0].length());
        String answer = new String();
        for(int num = 0; num < maxi; num++) {
            if(!hash.contains(Integer.valueOf(num))) {
                answer = binary(num);
                break;
            }
        }
        if(answer.length() < nums[0].length()) {
            String result = "";
            for(int i = 0; i < nums[0].length() - answer.length(); i++) {
                result+= '0';
            }
            answer = result + answer;
        }
        return answer;
    }
}