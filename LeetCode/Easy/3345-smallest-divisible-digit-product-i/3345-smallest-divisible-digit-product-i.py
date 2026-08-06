class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        while eval('*'.join(str(n))) % t: n += 1
        return n