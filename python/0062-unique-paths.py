class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        above_row = [1] * n
        for row in range(1, m):
            current_row = [1] * n
            for col in range(1, n):
                current_row[col] = current_row[col - 1] + above_row[col]
            above_row = current_row
        return above_row[n - 1]
