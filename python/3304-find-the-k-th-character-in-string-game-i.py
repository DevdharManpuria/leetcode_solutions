class Solution:
    def kthCharacter(self, k: int) -> str:
        length = 1
        while length < k:
            length *= 2
        ch = 'a'
        while length > 1:
            half = length // 2
            if k > half:
                k -= half
                ch = chr(((ord(ch) - ord('a') + 1) % 26) + ord('a'))
            length = half
        return ch