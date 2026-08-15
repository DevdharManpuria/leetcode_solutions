class Solution {
    public int longestSubsequence(int[] nums) {
        int ma = 0;
        int xo = 0;
        for(int i:nums){
            ma = Math.max(ma,i);
            xo ^= i;
        }
        if (ma == 0) return 0;
        if (xo == 0) return nums.length-1;
        return nums.length;
    }
}