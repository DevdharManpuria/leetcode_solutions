class Solution {
    public long maxAlternatingSum(int[] nums) {
        long[] marr = Arrays.stream(nums)
                            .mapToLong(n -> (long) n * n)
                            .sorted()
                            .toArray();
        int mid = marr.length / 2;
        long leftSum = Arrays.stream(marr, 0, mid).sum();
        long rightSum = Arrays.stream(marr, mid, marr.length).sum();
        return rightSum - leftSum;
    }
}