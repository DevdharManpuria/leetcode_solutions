class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) !=len(t):
            return False
        mp = [0]*26
        for i in s:
            mp[ord(i)-ord('a')]+=1
        for i in t:
            mp[ord(i)-ord('a')]-=1
        for i in mp:
            if i!=0:
                return False
        return True