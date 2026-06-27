import java.util.HashMap;

class Solution {
    public int maximumLength(int[] nums) {
        HashMap<Long, Integer> hm = new HashMap<>();
        for (int num : nums) {
            hm.put((long) num, hm.getOrDefault((long) num, 0) + 1);
        }
        
        int maxLen = 1;
        
        if (hm.containsKey(1L)) {
            int ones = hm.get(1L);
            maxLen = (ones % 2 == 0) ? ones - 1 : ones;
            hm.remove(1L);
        }
        
        for (long key : hm.keySet()) {
            long curr = key;
            int currLen = 0;
            
            while (hm.getOrDefault(curr, 0) >= 2) {
                currLen += 2;
                curr *= curr;
            }
            
            int peak = hm.containsKey(curr) ? 1 : -1;
            maxLen = Math.max(maxLen, currLen + peak);
        }
        
        return Math.max(1, maxLen);
    }
}