class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        blank,l,r=0,0,0
        for ch in moves:
            if ch=='L' :
                l+=1
            elif ch =='R' :
                r+=1
            else :
                blank+=1
        return abs(l-r) + blank