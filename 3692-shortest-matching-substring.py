class Solution:
    def shortestMatchingSubstring(self, s: str, p: str) -> int:
        def coalesce(L):
            for s in L:
                if s != '':
                    return s
            return L[-1]

        patterns = p.split('*')
        head = coalesce(patterns)
        l_min = sum(len(g) for g in patterns)
        l_shortest = float('inf')
        
        i = 0
        while 0 <= i < len(s) - l_min + 1:
            j1 = s.find(patterns[0], i)
            if j1 == -1:
                break
            j2 = s.find(patterns[1], j1 + len(patterns[0]))
            if j2 == -1:
                break
            j3 = s.find(patterns[2], j2 + len(patterns[1]))
            if j3 == -1:
                break
            l = j3 + len(patterns[2]) - j1
            l_shortest = min(l, l_shortest)
            if l_shortest == l_min:
                return l_shortest
            i = s.find(head, j1 + 1)
        return l_shortest if l_shortest < float('inf') else -1