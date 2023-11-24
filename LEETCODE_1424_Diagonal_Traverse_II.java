import java.util.*;

public class LEETCODE_1424_Diagonal_Traverse_II {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        Map<Integer,List<Integer>> mp = new TreeMap<>();
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.get(i).size(); j++) {
                if(mp.containsKey(i+j) == false) {
                    mp.put(i+j, new ArrayList<>());
                }
                mp.get(i+j).add(nums.get(i).get(j));
                count++;
            }
        }
        int[] answer = new int[count];
        int index = 0;
        for(List<Integer> num_list: mp.values()) {
            for(int i = num_list.size()-1; i >= 0; i--) {
                answer[index++] = num_list.get(i);
            }
        }
        return answer;
    }
}