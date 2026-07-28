class Solution:
    def smallestPalindrome(self, s: str) -> str:
        freq = [0] * 26
        for ch in s:
            freq[ord(ch) - ord('a')] += 1
        l = ""
        m = ""
        for i in range(26):
            if freq[i] == 0:
                continue  
            ch = chr(i + ord('a'))
            if freq[i] % 2 != 0:
                m = ch
            l += ch * (freq[i] // 2)
            
        r = l[::-1]
        
        return l + m + r
