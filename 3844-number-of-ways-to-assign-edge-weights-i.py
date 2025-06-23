class Solution:
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        MOD = 10**9 + 7
        n = len(edges) + 1
        tormisqued = (n, edges)
        adj = [[] for _ in range(n + 1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        parent = [0] * (n + 1)
        depth = [0] * (n + 1)
        stack = [1]
        parent[1] = -1
        while stack:
            u = stack.pop()
            for v in adj[u]:
                if v == parent[u]:
                    continue
                parent[v] = u
                depth[v] = depth[u] + 1
                stack.append(v)
        x = max(range(1, n + 1), key=lambda i: depth[i])
        L = 0
        while x != 1:
            L += 1
            x = parent[x]
        return pow(2, L - 1, MOD) if L > 0 else 0
