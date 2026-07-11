class Solution:
    def leastInterval(self, tasks: list[str], n: int) -> int:
        count = [0] * 26  # count of each char
        for task in tasks:
            count[ord(task) - ord('A')] += 1
        count.sort()  # sort to get the char with max occurrences
        maxf = count[25]  # max frequency char count = maxf
        idle = (maxf - 1) * n  # amount of idle time we have
        for i in range(24, -1, -1):
            idle -= min(maxf - 1, count[i])  # reduce idle time
        return max(0, idle) + len(tasks)  # total time