class Solution(object):
    def findContentChildren(self, g, s):
        n, m, l, r = len(g), len(s), 0, 0
        g.sort()
        s.sort()
        while l < m and r < n:
            if s[l] >= g[r]:
                r+=1
            l+=1
        return r