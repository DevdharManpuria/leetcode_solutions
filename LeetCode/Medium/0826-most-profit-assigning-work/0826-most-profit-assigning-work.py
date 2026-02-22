class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        n = len(difficulty)
        jobs = list(zip(difficulty, profit))
        jobs.sort()
        worker.sort()
        res = 0
        i = 0
        best = 0
        for w in worker:
            while i < n and jobs[i][0] <= w:
                best = max(best, jobs[i][1])
                i += 1
            res += best
        return res