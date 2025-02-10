import java.util.*;

class NumberContainers {

    private Map<Integer, Set<Integer>> hash = new HashMap<>();
    private Map<Integer, Integer> arr = new HashMap<>();

    public NumberContainers() {
        return;
    }
    
    public void change(int index, int number) {
        // Find the number which was previously stored at `index`
        int oldNumber = this.arr.containsKey(index) ? this.arr.get(index) : -1;
        if(oldNumber != -1) {
            this.hash.get(oldNumber).remove(index);
        }

        // Store `number` at `index`
        this.arr.put(index, number);
        if(!this.hash.containsKey(number)) {
            this.hash.put(number, new TreeSet<>());
        }
        this.hash.get(number).add(index);
    }
    
    public int find(int number) {
        if(!this.hash.containsKey(number)) {
            return -1;
        }
        Iterator<Integer> itr = this.hash.get(number).iterator();
        return itr.hasNext() ? itr.next() : -1;
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */