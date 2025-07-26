class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        int totalSum = 0;
        int F = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            F += i * nums[i];
        }
        int max = F;
        for (int k = 1; k < n; k++) {
            int rotatedOutIndex = n - k;
            F = F + totalSum - n * nums[rotatedOutIndex];
            max = Math.max(max, F);
        }
        return max;
    }
}