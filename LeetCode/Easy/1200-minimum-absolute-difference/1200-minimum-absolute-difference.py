class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        n = len(arr)
        min_diff = arr[1] - arr[0]
        for i in range(n - 1):
            min_diff = min(min_diff, arr[i + 1] - arr[i])
        sol = []
        for i in range(n - 1):
            if arr[i + 1] - arr[i] == min_diff:
                sol.append([arr[i], arr[i + 1]])
        return sol