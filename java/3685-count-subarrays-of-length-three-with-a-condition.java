class Solution {
    public int countSubarrays(int[] nums) {
        if(nums.length < 3) return 0;
        int cnt = 0;
        for(int i = 0; i < nums.length - 2; i++) {
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if (b % 2 == 0 && a + c == b / 2) {
                cnt++;
            }
        }
        return cnt;
    }
}
