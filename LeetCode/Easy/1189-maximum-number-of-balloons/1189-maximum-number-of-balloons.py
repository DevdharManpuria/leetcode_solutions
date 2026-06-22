class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        mp = Counter(text)
        return min( mp['b'], mp['a'], mp['n'], mp['l'] // 2, mp['o'] // 2 )