class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0); //count of each char
        for (char task : tasks) 
            count[task - 'A']++;
        sort(count.begin(), count.end()); // sort to get the char with max occurences
        int maxf = count[25]; // max frequency char count = maxf
        int idle = (maxf - 1) * n; // amount of idle time we have (maxf - 1) gaps as maxf elements placed and each gap has n spaces
        for (int i = 24; i >= 0; i--) 
            idle -= min(maxf - 1, count[i]); // reduce count of each char from the idle time
        return max(0, idle) + tasks.size(); // return 1 unit of time for each task and then any extra time need (if idle positive)
    }
};