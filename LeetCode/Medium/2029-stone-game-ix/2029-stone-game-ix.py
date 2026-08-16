class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        f = [0,0,0]
        for i in stones:
            f[i%3]+=1
        return (f[1] > 0 and f[2] > 0) if f[0]%2==0 else abs(f[2]-f[1]) > 2