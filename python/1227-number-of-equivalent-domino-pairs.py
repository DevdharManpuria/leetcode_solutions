class Solution:
    @staticmethod
    def numEquivDominoPairs(dominoes: List[List[int]]) -> int:
        counter = [0] * 100  
        for domino in dominoes:
            a, b = domino
            normalized = a * 10 + b if a < b else b * 10 + a
            counter[normalized] += 1
        return sum(count * (count - 1) // 2 for count in counter)
