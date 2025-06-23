class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        c = Counter(n for arr in grid for n in arr)
        for k in c: 
            if (grid[0][0] - k) % x: return -1
        a, prv, cur, mn, mx = [], 0, 0, min(c), max(c)
        for n in range(mn, mx + 1, x):
            a.append(prv + cur)
            prv, cur = a[-1], cur + c[n]
        ret, cur, nxt = inf, 0, 0
        for n in range(mx, mn - 1, -x):
            ret = min(ret, a.pop() + cur + nxt)
            cur, nxt = cur + c[n], cur + nxt
        return ret