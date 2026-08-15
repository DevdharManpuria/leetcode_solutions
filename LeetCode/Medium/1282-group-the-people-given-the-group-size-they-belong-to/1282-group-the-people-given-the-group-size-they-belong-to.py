class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        ans = []
        mp = defaultdict(list)
        for i in range(0,len(groupSizes)):
            s = groupSizes[i]
            mp[s].append(i)
            if len(mp[s]) == s:
                ans.append(mp[s])
                mp[s]=[]
        return ans