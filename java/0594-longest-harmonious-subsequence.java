class Solution {
    public int findLHS(int[] nums) {
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        for (int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }
        int maxLength = 0;
        for (int key : freqMap.keySet()) {
            if (freqMap.containsKey(key + 1)) {
                int totalLength = freqMap.get(key) + freqMap.get(key + 1);
                maxLength = Math.max(maxLength, totalLength);
            }
        }
        return maxLength;
    }
}