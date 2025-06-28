class Solution:
    def maxSubsequence(self, nums, k):
        value_with_index = [(num, i) for i, num in enumerate(nums)]
        value_with_index.sort(key=lambda x: -x[0])
        top_k = sorted(value_with_index[:k], key=lambda x: x[1])
        return [num for num, _ in top_k]
