import java.util.*;

public class LEETCODE_18_4SUM {
    
    private List<List<Integer>> solve(int first, int target, int[] nums) {
        Set<List<Integer>> result = new HashSet<>();
        int len = nums.length;
        for(int next = first + 1; next < len - 2; next++) {
            int start = next + 1, end = len - 1;
            while (start <= end) {
                if((long)nums[first] + (long)nums[next] + (long)nums[start] + (long)nums[end] == (long)target) {
                    result.add(Arrays.asList(nums[first], nums[next], nums[start], nums[end]));
                    start++;
                    end--;
                }
                else if((long)nums[first] + (long)nums[next] + (long)nums[start] + (long)nums[end] < (long)target) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }
        return new ArrayList<>(result);
    }

    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        Set<List<Integer>> answer = new HashSet<>();
        int len = nums.length;
        for(int i = 0; i < len - 3; i++) {
            List<List<Integer>> result = this.solve(i, target, nums);
            answer.addAll(result);
        }
        return new ArrayList<>(answer);
    }
}