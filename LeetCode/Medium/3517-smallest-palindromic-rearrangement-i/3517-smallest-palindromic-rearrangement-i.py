class Solution:
    def smallestPalindrome(self, s: str) -> str:
        freq = Counter(s)        
        chars = sorted(freq.keys())
        m = next((c for c, count in freq.items() if count % 2), "")
        l = "".join(c * (freq[c] // 2) for c in chars)
        return l + m + l[::-1]