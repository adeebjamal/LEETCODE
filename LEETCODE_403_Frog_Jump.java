import java.util.*;

class Solution {

    private Set<Integer> hash = new HashSet<>();
    private int lastStoneIndex = -1;
    private Map<String, Boolean> dp = new HashMap<>();

    private boolean f(int index, int currentJumpSize) {
        if(currentJumpSize == 0) {
            return false;
        }
        if(index == this.lastStoneIndex) {
            return true;
        }
        if(!this.hash.contains(index)){
            return false;
        }
        String key = index + "_" + currentJumpSize;
        if(this.dp.containsKey(key) == true) {
            return this.dp.get(key);
        }
        boolean result = false;
        result = result || this.f(index + currentJumpSize, currentJumpSize + 1);
        result = result || this.f(index + currentJumpSize, currentJumpSize - 1);
        result = result || this.f(index + currentJumpSize, currentJumpSize);
        this.dp.put(key, result);
        return result;
    }

    public boolean canCross(int[] stones) {
        this.lastStoneIndex = stones[stones.length - 1];
        for(int stone: stones) {
            this.hash.add(stone);
        }
        return this.f(stones[0], 1);
    }
}