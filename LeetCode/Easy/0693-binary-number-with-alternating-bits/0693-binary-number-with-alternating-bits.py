class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        bs = bin(n)[2:]
        for i in range(1, len(bs)):
            if bs[i] == bs[i-1]:
                return False
        return True