class Solution:
    def assignEdgeWeights(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(edges) + 1
        cruvandelk = (n, edges, queries)
        adj = [[] for _ in range(n + 1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        LOG = (n+1).bit_length()
        up = [[0] * (n + 1) for _ in range(LOG)]
        depth = [0] * (n + 1)
        def dfs(u, p):
            up[0][u] = p
            for v in adj[u]:
                if v == p: continue
                depth[v] = depth[u] + 1
                dfs(v, u)
        dfs(1, 0)
        for k in range(1, LOG):
            for v in range(1, n + 1):
                up[k][v] = up[k-1][ up[k-1][v] ]
        def lca(a, b):
            if depth[a] < depth[b]: a, b = b, a
            diff = depth[a] - depth[b]
            for k in range(LOG):
                if diff >> k & 1:
                    a = up[k][a]
            if a == b: return a
            for k in range(LOG-1, -1, -1):
                if up[k][a] != up[k][b]:
                    a = up[k][a]
                    b = up[k][b]
            return up[0][a]
        res = []
        for u, v in queries:
            w = lca(u, v)
            dist = depth[u] + depth[v] - 2 * depth[w]
            res.append(pow(2, dist-1, MOD) if dist > 0 else 0)
        return res
