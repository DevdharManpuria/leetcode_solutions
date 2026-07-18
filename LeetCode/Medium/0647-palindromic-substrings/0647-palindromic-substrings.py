from functools import lru_cache
class Solution:
    def countSubstrings(self, s: str) -> int:
        @lru_cache(maxsize = None)
        def isp(i: int,j: int) -> bool:
            if i>=j:
                return True
            if s[i] != s[j]:
                return False
            return isp(i+1,j-1)
        n = len(s)
        count = 0
        for i in range(n):
            for j in range(i,n):
                if isp(i,j):
                    count += 1
        return count
