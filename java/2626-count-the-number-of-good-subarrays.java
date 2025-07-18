public class Solution {
    public long countGood(int[] nums, int k) {
        int n = nums.length;
        if (n < 2) 
            return 0;
        
        Map<Integer, Integer> countMap = new HashMap<>(n, 0.99f);
        long goodSubArrays = 0L;
        long current = 0L;
        int left = 0;
        int right = -1;
        while (left < nums.length) {
            if (current < k) {
                if (++right == nums.length) {
                    break;
                }
          
                Integer num = nums[right];
                Integer count = countMap.get(num);
                if (count == null) {
                    count = 1;
                } else {
                    current += count;
                    if (current >= k) {
                        goodSubArrays += nums.length - right;
                    }
                    count = count + 1;
                }
                countMap.put(num, count);
            } else {
                Integer num = nums[left++];
                int count = countMap.get(num) - 1;
                if (count > 0) {
                    countMap.put(num, count);
                    current -= count;
                } else {
                    countMap.remove(num);
                }
                if (current >= k) {
                    goodSubArrays += nums.length - right;
                }
            }
        }
        return goodSubArrays;
    }
}