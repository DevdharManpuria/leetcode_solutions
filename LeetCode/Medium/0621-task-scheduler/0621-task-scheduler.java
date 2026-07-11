import java.util.Arrays;
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] count = new int[26]; // count of each char
        for (char task : tasks)
            count[task - 'A']++;
        Arrays.sort(count); // sort to get the char with max occurrences
        int maxf = count[25]; // max frequency char count = maxf
        int idle = (maxf - 1) * n; // amount of idle time we have
        for (int i = 24; i >= 0; i--)
            idle -= Math.min(maxf - 1, count[i]); // reduce idle time
        return Math.max(0, idle) + tasks.length; // total time
    }
}