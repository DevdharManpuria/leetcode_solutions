class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        if k == 1 :
            return "1" if "1" in s else "" 
        n = len(s)
        minL = math.inf
        ans = ""
        ansList = []
        currC = 0

        l = 0
        while l < n and s[l] != "1" :
            l += 1
        currC += 1

        for r in range(l+1, n) :
            if s[r] == "1" :
                currC += 1

                if currC == k :
                    if r - l == minL :
                        ansList.append(s[l:r+1])
                    if r - l < minL :
                        ansList = []
                        minL = r - l
                        ansList.append(s[l:r+1])
                    l += 1

                    while l < r :
                        if s[l] == "1" :
                            break
                        l += 1
                    currC -= 1
        ansList.sort()
        return ansList[0] if ansList else ""