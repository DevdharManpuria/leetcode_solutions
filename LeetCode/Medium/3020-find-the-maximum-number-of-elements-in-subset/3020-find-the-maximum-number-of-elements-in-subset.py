class Solution:
    def maximumLength(self, nums: list[int]) -> int:
        hm = Counter(nums)
        max_len = hm[1] - (hm[1] % 2 == 0) if 1 in hm else 1
        if 1 in hm:
            del hm[1]
        for key in hm:
            curr = key
            curr_len = 0
            while hm[curr] >= 2:
                curr_len += 2
                curr *= curr
            peak = 1 if hm[curr] > 0 else -1
            max_len = max(max_len, curr_len + peak)
        return max(1, max_len)