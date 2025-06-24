class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        values = defaultdict(list)
        for i in range(len(nums)):
            values[nums[i]].append(i)
        res = 0
        for v, l in values.items():
            for i in range(len(l)):
                for j in range(i + 1, len(l)):
                    if (l[i] * l[j]) % k == 0:
                        res += 1
        return res
        