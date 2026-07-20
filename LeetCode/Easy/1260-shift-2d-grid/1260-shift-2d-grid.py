class Solution:
    def shiftGrid(self, grid: list[list[int]], k: int) -> list[list[int]]:
        m, n = len(grid), len(grid[0])
        flat = [grid[i][j] for i in range(m) for j in range(n)]
        k %= (m * n)
        shifted = flat[-k:] + flat[:-k]
        return [shifted[i * n : (i + 1) * n] for i in range(m)]
