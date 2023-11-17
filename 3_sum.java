import java.util.*;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>> result = new HashSet<>();
        for(int i = 0; i < nums.length-2; i++) {
            int start = i+1, end = nums.length-1;
            while(start < end) {
                if(nums[i] + nums[start] + nums[end] == 0) {
                    List<Integer> temp = new ArrayList<>();
                    temp.add(nums[i]);
                    temp.add(nums[start]);
                    temp.add(nums[end]);
                    result.add(temp);
                    start++;
                    end--;
                }
                else if(nums[i] + nums[start] + nums[end] > 0) {
                    end--;
                }
                else {
                    start++;
                }
            }
        }
        return new ArrayList<>(result);
    }
}